#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MESSAGE_MAX_LEN 32

typedef enum {
    STATE_WAIT_START,
    STATE_RECEIVING,
    STATE_PROCESSING,
    STATE_SENDING_RESPONSE
} State;

typedef enum {
    EVENT_NONE,
    EVENT_BYTE_RECEIVED,
    EVENT_MESSAGE_COMPLETE,
    EVENT_SEND_DONE
} Event;

typedef struct {
    uint8_t buffer[MESSAGE_MAX_LEN];
    uint8_t length;
} Message;

State currentState = STATE_WAIT_START;
Message currentMessage;
uint8_t byteReceived;
Event currentEvent = EVENT_NONE;

// Simulate message parsing
int is_message_complete(const Message *msg) {
    return msg->length > 0 && msg->buffer[msg->length - 1] == '\n';
}

// Simulate message processing
void process_message(const Message *msg) {
    printf("Processing message: %.*s", msg->length, msg->buffer);
}

// Simulate sending response
void send_response() {
    printf("Sending response: OK\n");
    currentEvent = EVENT_SEND_DONE;
}

// FSM Handler
void state_machine_run(Event event) {
    switch (currentState) {
        case STATE_WAIT_START:
            if (event == EVENT_BYTE_RECEIVED) {
                currentMessage.buffer[0] = byteReceived;
                currentMessage.length = 1;
                currentState = STATE_RECEIVING;
            }
            break;

        case STATE_RECEIVING:
            if (event == EVENT_BYTE_RECEIVED) {
                if (currentMessage.length < MESSAGE_MAX_LEN) {
                    currentMessage.buffer[currentMessage.length++] = byteReceived;
                    if (is_message_complete(&currentMessage)) {
                        currentEvent = EVENT_MESSAGE_COMPLETE;
                    }
                }
            } else if (event == EVENT_MESSAGE_COMPLETE) {
                currentState = STATE_PROCESSING;
            }
            break;

        case STATE_PROCESSING:
            process_message(&currentMessage);
            currentState = STATE_SENDING_RESPONSE;
            break;

        case STATE_SENDING_RESPONSE:
    if (event == EVENT_NONE) {
        send_response();  // Called once
    } else if (event == EVENT_SEND_DONE) {
        currentState = STATE_WAIT_START;
        currentMessage.length = 0;
    }
    break;


        default:
            currentState = STATE_WAIT_START;
            break;
    }
}

// Simulated input loop
void simulate_input(const char *input) {
    for (size_t i = 0; i < strlen(input); i++) {
        byteReceived = input[i];
        currentEvent = EVENT_BYTE_RECEIVED;
        state_machine_run(currentEvent);

        if (currentEvent == EVENT_MESSAGE_COMPLETE) {
            state_machine_run(EVENT_MESSAGE_COMPLETE);
            state_machine_run(EVENT_SEND_DONE);
        }
    }
}

int main(void) {
    simulate_input("Hello, device!\n");
    return 0;
}
