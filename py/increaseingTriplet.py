def increasingTriplet(nums):
    assert isinstance(nums, list)
    if len(nums) < 3:
        return False

    seq1, seq2 = nums[0], nums[0]
    status = 1
    for j, i in enumerate(nums[1:]):
        if i > seq1 and status == 1:
            seq2 = i
            status = 2
        if i > seq2 and status == 2:
            return True
        if i < seq1 and status == 1:
            seq1 = i
        if i > seq1 and i < seq2 and status == 2:
            seq2 = i
        if i < seq1 and status == 2:
            return increasingTriplet(nums[j + 1:])


def main():
    test = [1, 2, -10, -8, -7]
    print increasingTriplet(test)

if __name__ == '__main__':
    main()
