import string

# Define the ciphertext and the alphabet
ciphertext = "EfsbwefcsmdcrugcrvthccdpjlrwdfllrgwlbwcyzdqdvpkshkleshadqwbhwcwclscsmlccatsyboilscgpePrwbwtkddkdgpawzdhgsyqzpltmbjfwcghlscytqtqycghlhwwpygtotrvlztavizpisnelwptusybvwoggpfzrvtjamwcltltpnzpculscosgarwdfzdhwadacswmwhwgdcrtktpwcyemhgsyqaxltkddjeybiepqgpypqkxlsmiilscgaarfhtkebocyppculscwgepqgpypqptayeftsozmegwghxuljcgtfqwcwdqfxnljgtln."
alphabet = string.ascii_uppercase

# Loop over possible key lengths
for key_length in range(1, len(ciphertext)):

    # Initialize the key and the plaintext
    key = ""
    plaintext = ""

    # Loop over the characters in the key
    for i in range(key_length):

        # Initialize the frequency table for this column of the ciphertext
        freqs = {letter: 0 for letter in alphabet}

        # Count the frequency of each letter in this column of the ciphertext
        for j in range(i, len(ciphertext), key_length):
            freqs[ciphertext[j]] += 1

        # Find the most frequent letter in this column of the ciphertext
        max_freq = 0
        likely_letter = None
        for letter, freq in freqs.items():
            if freq > max_freq:
                max_freq = freq
                likely_letter = letter

        # Append the likely letter to the key
        key += alphabet[(alphabet.index(likely_letter) - alphabet.index('E')) % 26]

    # Decrypt the ciphertext using the key
    for i in range(len(ciphertext)):
        key_char = key[i % len(key)]
        ciphertext_char = ciphertext[i]
        plaintext += alphabet[(alphabet.index(ciphertext_char) - alphabet.index(key_char)) % 26]

    # Print the key and the plaintext
    print("Key:", key)
    print("Plaintext:", plaintext)
