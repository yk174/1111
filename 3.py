
# Encrypt using XOR
def xor_encrypt(text, key):
    xored = "".join(
        chr(ord(x) ^ ord(y))
        for x, y in zip(
            text, key * (len(text) // len(key)) + key[: len(text) % len(key)]
        )
    )
    return xored

# Decode using XOR
def xor_decrypt(encrypted_text, key):
    return "".join(
        chr(ord(x) ^ ord(y))
        for x, y in zip(
            encrypted_text,
            key * (len(encrypted_text) // len(key))
            + key[: len(encrypted_text) % len(key)],
        )
    )

# Usage example
mytext = input("请输入input.txt的内容")
key = 20227815
encrypted_text = xor_encrypt(mytext, key)
print(f"Encrypted text: {encrypted_text}")

decrypted_text = xor_decrypt(encrypted_text, key)
print(f"Decrypted text: {decrypted_text}")