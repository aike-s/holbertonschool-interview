#!/usr/bin/python3
"""
Min operations
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to result in exactly n H
    """
    H = 1
    copy_all = 0
    num_operations = 0

    while (H != n and n > 0):
        # Copy all action
        if n % H == 0 or H == 1:
            copy_all = H
            num_operations += 1
        # Paste action
        H += copy_all
        num_operations += 1

    return num_operations
