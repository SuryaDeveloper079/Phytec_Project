#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MESSAGE_MAX_LEN 32

// Finite State Machine States
typedef enum {
    STATE_WAIT_START,
    STATE_RECEIVING,
    STATE_PROCESSING,
    STATE_SENDING_RESPONSE
} State;

// Events that trigger state transitions
typedef enum {
    EVENT_NONE,
    EVENT_BYTE_RECEIVED,
    EVENT_MESSAGE_COMPLETE,
    EVENT_SEND_DONE
} Event;

// Events that trigger state transitions
typedef struct {
    uint8_t buffer[MESSAGE_MAX_LEN];
    uint8_t length;
} Message;

// Global state variables
State currentState = STATE_WAIT_START;
Message currentMessage;
uint8_t byteReceived;

// Function to check if message is complete (ends with newline)
int is_message_complete(const Message *msg) {
    return msg->length > 0 && msg->buffer[msg->length - 1] == '\n';
}

// Simulate message processing
void process_message(const Message *msg) {
    printf("Processing message: %.*s", msg->length, msg->buffer);
}

// Simulate sending a response
void send_response() {
    printf("Sending response: OK\n");
}

// FSM Handler Main state machine logic
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
                        currentState = STATE_PROCESSING;
                    }
                }
            }
            break;

        case STATE_PROCESSING:
            process_message(&currentMessage);
            currentState = STATE_SENDING_RESPONSE;
            break;

        case STATE_SENDING_RESPONSE:
            send_response();
            // Reset for next message
            currentState = STATE_WAIT_START;
            currentMessage.length = 0;// Reset message buffer
            break;

        default:
            currentState = STATE_WAIT_START;
            break;
    }
}

// Simulate receiving input character-by-character
void simulate_input(const char *input) {
    size_t len = strlen(input);
    for (size_t i = 0; i < len; i++) {
        byteReceived = input[i];
        state_machine_run(EVENT_BYTE_RECEIVED);

        
        // Run processing and response states if triggered
        if (currentState == STATE_PROCESSING) {
            state_machine_run(EVENT_NONE); // triggers processing
            state_machine_run(EVENT_NONE); // triggers sending response
        }
    }
}

int main(void) {
    simulate_input("Hello, device!\n");
    simulate_input("How are you?\n");
    return 0;
}
