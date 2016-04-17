def main():
    for i in range(100):
        if (i**2) % 100 == i:
            print '%d ** 2 = %d'%(i,i**2)

if __name__ == '__main__':
    main()