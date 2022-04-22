#!/usr/bin/python3
"""498#0 - Lockboxes"""


from multiprocessing.connection import wait


def canUnlockAll(boxes):
    """determines if all the boxes can be opened"""
    pending_boxes = [0]
    visited_boxes = []
    while len(pending_boxes):
        if (pending_boxes[0] < len(boxes)):
            for key in boxes[pending_boxes[0]]:
                if (isinstance(key, int) and
                   (key not in pending_boxes and key not in visited_boxes)):
                    pending_boxes.append(key)
        visited_boxes.append(pending_boxes[0])
        pending_boxes.pop(0)
    for box in range(len(boxes)):
        if box not in visited_boxes:
            return False
    return True
