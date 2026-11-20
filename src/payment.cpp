
#include "payment.h"

#include <cstdlib>

static bool gatewayAuthorize(const char *key, double amount)
{
    return key[0] != '\0' && amount > 0.0;
}

bool processPayment(double amount)
{
    const char *key = std::getenv("PAYMENT_KEY");

    if (key == nullptr)
    {
        return false;
    }

    return gatewayAuthorize(key, amount);
}
