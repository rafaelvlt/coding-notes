class LinkedList:
    def __init__(self):
        self.head = None
        self.length = 0

    def is_empty(self):
        return True if not self.length else False

    def add(self, element):
        node = self.Node(element)
        if (self.is_empty()):
            self.head = node
        else:
            current_node = self.head
            while current_node.next is not None:
                current_node = current_node.next

            current_node.next = node

        self.length += 1

    def remove(self, element):
        previous_node = None
        current_node = self.head

        while current_node is not None and current_node.element != element:
            previous_node = current_node
            current_node = current_node.next

        if current_node is None:
            return
        elif previous_node is not None:
            previous_node.next = current_node.next
        else:
           self.head = current_node.next 

        self.length -= 1


    class Node:
        def __init__(self, element):
            self.element = element
            self.next = None

