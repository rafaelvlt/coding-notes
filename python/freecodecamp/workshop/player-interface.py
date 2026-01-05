import random
from abc import ABC, abstractmethod

class Player(ABC):
    def __init__(self) -> None:
        self.moves = []
        self.position = (0, 0)
        self.path = [self.position]

    def make_move(self) -> tuple:
        choice = random.choice(self.moves)
        self.position = (self.position[0] + choice[0], self.position[1] + choice[1])
        self.path.append(self.position)
        return self.position

    @abstractmethod
    def level_up(self):
        pass

class Pawn(Player):
    def __init__(self) -> None:
        super().__init__()
        self.moves = [(1, 0), (0, 1), (-1, 0), (0, -1)]

    def level_up(self) -> None:
        self.moves.extend([(1, 1), (-1, 1), (1, -1), (-1, -1)])
