import re
def extract_number_prefix(line):
    match = re.match(r'^#?\s*(\d+(\.\d+)*) ', line)
    return match.group(1) if match else None

while(True):
    s = input("Q:")
    print(extract_number_prefix(s))
