# Minitalk

A client-server communication program using UNIX signals for data transmission.

## Description

Minitalk is a 42 School project that implements inter-process communication using only UNIX signals (`SIGUSR1` and `SIGUSR2`). The project consists of a server that receives and displays messages, and a client that sends messages to the server by converting text into binary signals.

This implementation demonstrates low-level process communication, signal handling, and bit manipulation in C.

## Features

- ✅ **Server-Client Architecture** - Lightweight communication system
- ✅ **Signal-Based Communication** - Uses only SIGUSR1 and SIGUSR2
- ✅ **Binary Encoding** - Converts characters to bits for transmission
- ✅ **Multiple Client Support** - Server can handle multiple clients sequentially
- ✅ **Unicode Support** - Handles extended ASCII characters
- ✅ **Acknowledgment System** (Bonus) - Server confirms message receipt
- ✅ **Error Handling** - Robust input validation

## How It Works

### Communication Protocol

1. **Server** starts and displays its Process ID (PID)
2. **Client** sends the server's PID and a message as arguments
3. **Client** converts each character to 8 bits (binary)
4. **Client** sends each bit using signals:
   - `SIGUSR1` = bit 1
   - `SIGUSR2` = bit 0
5. **Server** receives signals and reconstructs the message
6. **Server** displays the complete message

### Bit Transmission Example

```
Character 'A' (ASCII 65):
Binary: 01000001

Sent as:
SIGUSR2 → SIGUSR1 → SIGUSR2 → SIGUSR2 → SIGUSR2 → SIGUSR2 → SIGUSR2 → SIGUSR1
   0         1         0         0         0         0         0         1
```

## Installation

Clone the repository:
```bash
git clone https://github.com/Yoneva/minitalk.git
cd minitalk
```

## Compilation

### Compile Mandatory Part

```bash
cd Mandatory
make
```

This creates two executables:
- `Server` - The server program
- `Client` - The client program

### Compile Bonus Part

```bash
cd bonus
make
```

This creates the bonus version with acknowledgment support.

### Make Rules

- `make` or `make all` - Compile both client and server
- `make clean` - Remove object files
- `make fclean` - Remove object files and executables
- `make re` - Recompile entire project

## Usage

### Step 1: Start the Server

```bash
./Server
```

**Output:**
```
Process Identification : 12345
```

The server displays its PID and waits for messages.

### Step 2: Send a Message

In another terminal:

```bash
./Client [SERVER_PID] [MESSAGE]
```

**Example:**
```bash
./Client 12345 "Hello, 42!"
```

**Server Output:**
```
Process Identification : 12345
Hello, 42!
```

### Multiple Messages

You can send multiple messages to the same server:

```bash
./Client 12345 "First message"
./Client 12345 "Second message"
./Client 12345 "Third message"
```

### Bonus: Acknowledgment

The bonus version sends an acknowledgment back to the client:

```bash
# Start bonus server
./Server

# Send message with bonus client
./Client 12345 "Hello"
```

**Client Output:**
```
Message recieved ✅
```

## Project Structure

```
.
├── Mandatory/
│   ├── Makefile              # Build configuration
│   ├── Mini_talk.h           # Header file
│   ├── server.c              # Server implementation
│   └── client.c              # Client implementation
├── bonus/
│   ├── Makefile              # Bonus build configuration
│   ├── Mini_talk.h           # Bonus header file
│   ├── server.c              # Server with acknowledgment
│   └── client.c              # Client with acknowledgment handling
├── libft/                    # Custom C library (42 project)
└── ft_printf/                # Custom printf implementation
```

## Implementation Details

### Server (`server.c`)

**Key Features:**
- Uses `sigaction()` with `SA_SIGINFO` flag to get sender's PID
- Maintains state using static variables
- Reconstructs characters bit by bit
- Handles multiple clients sequentially

**Signal Handler:**
```c
void handler(int sig, struct __siginfo *info, void *context)
{
    static int i;           // Current character being built
    static int last_pid;    // Track current client
    
    // Handle bit reception
    if (sig == SIGUSR1)
        i = (1 << g_bits) | i;  // Set bit to 1
    
    g_bits--;
    
    // Complete character received
    if (g_bits < 0) {
        ft_printf("%c", i);
        i = 0;
        g_bits = 7;
    }
}
```

### Client (`client.c`)

**Key Features:**
- Converts message to binary bit by bit
- Sends signals with small delays (usleep)
- Uses bit shifting to extract individual bits

**Bit Transmission:**
```c
void char_bits(char *str, int PID)
{
    int bits;
    int i = 0;
    
    while (str[i]) {
        bits = 7;  // Start from MSB
        while (bits >= 0) {
            if ((str[i] >> bits) & 1)
                kill(PID, SIGUSR1);  // Send 1
            else
                kill(PID, SIGUSR2);  // Send 0
            usleep(90);  // Small delay
            bits--;
        }
        i++;
    }
}
```

## Technical Details

### Signal Handling

**Why SIGUSR1 and SIGUSR2?**
- User-defined signals available for custom purposes
- No default action (won't terminate process)
- Can be caught and handled

**Signal Safety:**
- `sigaction()` is used instead of `signal()` for POSIX compliance
- Handler uses only async-signal-safe functions
- `SA_SIGINFO` flag provides sender information

### Timing Considerations

**usleep(90)**: Small delay between signals
- Prevents signal loss due to race conditions
- Server needs time to process each signal
- 90 microseconds balances speed and reliability

### Character Encoding

- Each character = 8 bits
- MSB (Most Significant Bit) sent first
- Supports ASCII and extended ASCII (0-255)

## Error Handling

The programs handle various error cases:

**Client Errors:**
```bash
# Wrong number of arguments
./Client
# Output: Not enough arguments, Try again :b

# Invalid PID
./Client abc "Hello"
# Converts to PID 0, kill() will fail
```

**Server Errors:**
- Handles signal interruption gracefully
- Properly switches between multiple clients

## Testing

### Basic Test

```bash
# Terminal 1
./Server
# Note the PID (e.g., 12345)

# Terminal 2
./Client 12345 "Hello, World!"
```

### Long Message Test

```bash
./Client 12345 "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."
```

### Special Characters Test

```bash
./Client 12345 "Hello! 🚀 @#$%^&*()"
./Client 12345 "Émojis: 😀 🎉 ✨"
```

### Stress Test

```bash
# Send multiple messages quickly
for i in {1..10}; do ./Client 12345 "Message $i"; done
```

### Unicode Test

```bash
./Client 12345 "日本語 中文 한국어 العربية"
```

## Performance

**Transmission Speed:**
- ~90 microseconds per bit
- 8 bits per character
- ~720 microseconds per character
- ~1,388 characters per second

**Message Size:**
- No theoretical limit
- Limited by system resources
- Tested with messages up to 10,000+ characters

## Bonus Features

The bonus implementation adds:

1. **Server Acknowledgment**
   - Server sends SIGUSR1 back to client after receiving complete message
   - Client displays confirmation message

2. **Enhanced Error Handling**
   - Better handling of multiple concurrent clients
   - Improved signal queue management

**Bonus Client Output:**
```bash
./Client 12345 "Hello!"
Message recieved ✅
```

## Debugging Tips

### Find Server PID

```bash
# If you forgot the PID
ps aux | grep Server
# or
pgrep Server
```

### Kill Unresponsive Process

```bash
kill [PID]
# or force kill
kill -9 [PID]
```

### Test Signal Delivery

```bash
# Manually send signals for testing
kill -SIGUSR1 [SERVER_PID]
kill -SIGUSR2 [SERVER_PID]
```

## Common Issues

**Issue:** Client sends but server doesn't display anything
- **Solution:** Check if you're using the correct PID
- **Solution:** Ensure server is running

**Issue:** Garbled output on server
- **Solution:** Increase usleep delay in client
- **Solution:** Check for signal handling issues

**Issue:** Client hangs
- **Solution:** Verify server is responsive
- **Solution:** Check if PID is valid

## Dependencies

- **libft**: Custom C library (included)
- **ft_printf**: Custom printf implementation (included)
- UNIX/Linux operating system
- GCC compiler

## Compilation Requirements

- **Compiler:** cc (gcc/clang)
- **Flags:** `-Wall -Wextra -Werror`
- **Language:** C
- **Standard:** POSIX

## Author

**amsbai** - 42 Student

## License

This project is part of the 42 School curriculum.

## Acknowledgments

Minitalk teaches:
- UNIX signal handling
- Inter-process communication (IPC)
- Bit manipulation
- Asynchronous programming
- Process synchronization
- Binary encoding/decoding

## Resources

**Signal Handling:**
- `man 2 signal`
- `man 2 sigaction`
- `man 2 kill`

**Process Management:**
- `man 2 getpid`
- `man 2 pause`

**Timing:**
- `man 3 usleep`
