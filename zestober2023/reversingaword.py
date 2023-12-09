# Define a function that reverses a given string
def reverse_string(input_str):
    return input_str[::-1]

# Define the main function
def main():
    # Prompt the user to enter a ciphertext
    ciphertext = input("Enter the ciphertext: ")

    # Reverse the input string to decode it
    plaintext = reverse_string(ciphertext)

    # Print the decoded message
    print("Decoded message:", plaintext)

# Check if the script is being run as the main program
if __name__ == "__main__":
    # Call the main function
    main()
