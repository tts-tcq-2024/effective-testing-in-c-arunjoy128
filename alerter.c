#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
int testInCelcius = 0;

int mockNetworkAlert(float celcius) {
    testInCelcius = celcius;
    printf("MOCK ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 500;
}

int realNetworkAlert(float celcius) {
    printf("REAL ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    return (celcius > 200) ? 500 : 200;
}

void alertInCelcius(float farenheit, int(*networkAlertFunc)(float)) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertFunc(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount = alertFailureCount + 1;
    }
}


void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(103.6, mockNetworkAlert);
    alertInCelcius(400.5, mockNetworkAlert);
    assert(alertFailureCount == 2);
    printf("%d alerts failed \n\n", alertFailureCount);
    
    alertInCelcius(103.6, realNetworkAlert);
    alertInCelcius(400.5, realNetworkAlert);
    assert(alertFailureCount == 4);
    printf("%d alerts failed \n", alertFailureCount);
    printf("\nAll is well (maybe!)");
    return 0;
}
