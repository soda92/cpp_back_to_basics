#include <stdio.h>

#include "EventEmitter.h"

int main() {
    EventEmitter emitter;

    emitter.on("eventHello", [](const int& n) { printf("Hello %d", n); });

    emitter.emitSync("eventHello", 123);
}
