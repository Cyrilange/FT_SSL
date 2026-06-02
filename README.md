# ressources 

[rfc1321](https://datatracker.ietf.org/doc/html/rfc1321)

to obtain T 

void init_T_table(uint32_t *T) {
    for (int i = 1; i <= 64; i++) {
        T[i] = (uint32_t)(4294967296.0 * fabs(sin(i)));
    }
}

to obtain S 

## 🔒 Design Choices & Cryptographic Constraints

### Why Hardcoded Shift Tables (Array `S`) Over Dynamic Functions?

During the development of this MD5 implementation, we experimented with replacing the static shift array `S` (defining bitwise rotation distances) with a dynamic mathematical function to reduce binary size and eliminate "magic constants". 

However, we deliberately reverted to a static lookup table (`const int S[]`) for the following critical reasons:

1. **The Avalanche Effect Preservation:** The 16 unique shift values (`7, 12, 17, 22`, etc.) specified in **RFC 1321** were meticulously chosen by Ronald Rivest. They are not random; they are mathematically optimized to maximize *diffusion* (the avalanche effect), ensuring that a single bit change in the input cascades unpredictably throughout the entire state.

2. **Computational Hazards of Pseudo-Formulas:**
   Attempting to model these irregular constants using arithmetic modulo formulas or conditional branches (`if/else` steps) introduces translation friction. A single misplaced operator or operator-precedence mismatch results in complete hash corruption (e.g., getting an invalid state instead of the universal empty string hash `d41d8cd9...`).

3. **Performance & Zero-Overhead execution:**
   In production-grade cryptography, speed is paramount. Calculating the shift distance dynamically *inside* a loop that executes 64 times per 512-bit block adds unnecessary CPU overhead. A hardcoded array is stored directly in the `.rodata` (Read-Only Data) segment of the binary, allowing the CPU to fetch rotation distances with an immediate, $O(1)$ zero-overhead memory access.

4. **Code Readability & Compliance:**
   Keeping the explicit table allows any security auditor to instantly match the code against the official RFC specification, ensuring the implementation is trustworthy and verifiable.

### data 

exemple :
line 1 : [ABCD 0 7 1] -> 7, [DABC 1 12 2] -> 12, [CDAB 2 17 3] -> 17, [BCDA 3 22 4] -> 22# FT_SSL
