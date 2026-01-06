class HashTable:
    def __init__(self) -> None:
        self.collection = {}

    def hash(self, key: str) -> int:
        sum = 0
        for char in key:
            sum += ord(char)
        return sum

    def add(self, key: str, value) -> None:
        key_hash = self.hash(key)
        if (key_hash in self.collection):
            self.collection[key_hash][key] = value 
        else:
            self.collection[key_hash] = {}
            self.collection[key_hash][key] = value


    def remove(self, key):
        key_hash = self.hash(key)
        if (key_hash in self.collection):
            if (len(self.collection[key_hash]) > 1):
                del self.collection[key_hash][key]
            else:
                del self.collection[key_hash]
            
    def lookup(self, key):
        key_hash = self.hash(key)
        if (key_hash in self.collection):
            if (key in self.collection[key_hash]):
                return self.collection[key_hash][key]
            else:
                return None
        else:
            return None
