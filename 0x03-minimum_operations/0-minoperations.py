#!/usr/bin/python3
"""488#0 - Minimum Operations"""


def minOperations(n):
    """In a text file, there is a single character 'H'.
    Your text editor can execute only two operations in this file:
    'Copy All' and 'Paste'.
    Given a number n, write a method that calculates the fewest number
    of operations needed to result in exactly n 'H' characters in the file"""
    pichu, div = 0, 2
    while isinstance(n, int) and n > 1:
        while n % div:
            div += 1
        pichu += div
        n = int(n / div)
    return pichu
