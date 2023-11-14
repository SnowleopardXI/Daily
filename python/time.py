from datetime import datetime, timedelta

def int_to_crockford_base32(i):
    """
    Convert an integer to a Crockford's Base32 encoded string.
    Crockford's Base32 includes characters: 0-9, A-Z (excluding I, L, O, U)
    """
    chars = '0123456789ABCDEFGHJKMNPQRSTVWXYZ'
    result = ''

    # Convert the integer to a Base32 string
    while i > 0:
        i, remainder = divmod(i, 32)
        result = chars[remainder] + result

    # Ensure the length is 10 characters by padding with zeros if necessary
    result = result.rjust(10, '0')

    return result

def unix_timestamp_to_ulid_timestamp(unix_timestamp_ms):
    """
    Convert a Unix timestamp (in milliseconds) to a ULID timestamp.
    """
    return int_to_crockford_base32(unix_timestamp_ms)

# Example usage
unix_timestamp_ms = 1649606400 * 1000  # Example Unix timestamp (in milliseconds)
ulid_timestamp = unix_timestamp_to_ulid_timestamp(unix_timestamp_ms)
print(f"ULID Timestamp: {ulid_timestamp}")
