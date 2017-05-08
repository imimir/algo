import heapq

class Node(object):
    def __init__(self, left_node, right_node, value):
        self.left_node = left_node
        self.right_node = right_node
        self.value = value

    def isLeaf(self):
        return True if not self.left_node and not self.right_node else False

    _buffer = [] 
    _table = {}
    def huffmanTable(self, f):
        if self.isLeaf():
            to_delete = None
            for c in f:
                if self.value == f[c]:
                    Node._table[c] = list(Node._buffer)
                    to_delete = c

            if to_delete:
                del f[to_delete]
            Node._buffer.pop()
            return
        if self.left_node:
            Node._buffer.append("1")
            self.left_node.huffmanTable(f)
        if self.right_node:
            Node._buffer.append("0")
            self.right_node.huffmanTable(f)

        if len(Node._buffer): 
            Node._buffer.pop()
        else:
            result = {}
            for key in Node._table:
                result[key] = "".join(Node._table[key])

            return result
    def __lt__(self, other):
        return True 

def huffman(s):
    assert s

    queue = []
    characters = set(s)
    frequency = {}
    unique_characters = len(characters)
    code_length = 0
    for c in characters:
        frequency[c] = s.count(c)
        code_length += frequency[c]

    heapq.heapify(queue) 

    for c in characters:
        f  = frequency[c]
        heapq.heappush(queue, (f, Node(None, None, f)))

    while len(queue) > 1:
        iF, iNode = heapq.heappop(queue)
        jF, jNode = heapq.heappop(queue)
        nodeValue = iF + jF
        code_length += nodeValue
        heapq.heappush(queue, (nodeValue, Node(iNode, jNode, nodeValue))) 

    _, tree = heapq.heappop(queue)
    huffmanTable = {}
    if tree.isLeaf():
        code_length = len(s)
        huffmanTable = { characters.pop() : "0" }
    else:
        code_length -= tree.value
        huffmanTable = (tree.huffmanTable(frequency))

    print(unique_characters, code_length) 
    for c in huffmanTable:
        print(c, ": ", huffmanTable[c], sep="")

    result = ""
    for c in s:
        result += huffmanTable[c]

    print(result)

def main():
    s = input()
    huffman(s)

if __name__ == "__main__":
        main()
