import random
import sys

def main():
    if len(sys.argv) != 2:
        return
    cnt_symbols = int(sys.argv[1])
    file_name = "test_" + sys.argv[1] + ".txt"
    res = ""
    with open(file_name, "w") as f:
        res += sys.argv[1] + "\n"
        for _ in range(cnt_symbols):
            res += chr(random.randint(49, 51)) + " "
        f.write(res)

if __name__ == "__main__":
    main()