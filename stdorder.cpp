#include "stdorder.h"


StdOrder::StdOrder(const string& f, const string& l, const string& id, int n)
    : firstName(f), lastName(l), stdId(id), status(0), numOrder(n), next(nullptr) {}