from random import randint

class Node(object):
    def __init__(self, data: int):
        self.data = data
        self.next = None
    def __repr__(self) -> str:
        class_name = type(self).__name__
        return f"{class_name}(data = {self.data})"

def main() -> int:

    num_nodes = randint(5, 10)

    nodes = [Node(data=randint(0, 100)) for _ in range(num_nodes)]

    for i, node in enumerate(nodes):
        if i < num_nodes - 1:
            node.next = nodes[i + 1] # type: ignore
        print(f"The current node is {node}, and {f'the next node is {node.next}' if node.next else 'it is the last node'}")
    
    return 0

if __name__ == "__main__":

    main()
