class Node(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def isCircle(Node):
    if Node is None:
        return False
    first = Node
    second = Node
    while first.next and second.next.next:
        first = first.next
        second = second.next.next
        tag = first == second
        return tag
    return False
