from rectangle import Rectangle

class Main():

    def __init__(self, w, h, mud, dt, maxIter, recs):

        self.h = h
        self.w = w
        self.mud = mud
        self.dt = dt
        self.maxIter = maxIter
        self.recs = recs

    def run(self):
        iters = 0
        keepGoing = True
        velBellow = True
        while keepGoing:
            print(f"Iter {iters}")
            for index, rec in enumerate(self.recs):
                for i in range(index + 1, len(self.recs)):
                    newRec = rec.checkCollision(self.recs[i])
                    self.recs[i] = newRec
                    self.recs[index] = rec
                self.recs[index].update(self.mud, self.dt, self.w, self.h)
                if not rec.isStopped():
                    velBellow = False
                print(f"{rec.x} | {rec.y} | {rec.vx} | {rec.vy}")

            iters += 1
            if velBellow or iters >= self.maxIter:
                keepGoing = False



if __name__ == "__main__":
    rec = Rectangle(10, 5, 4, 13, 18, 0, 1)
    m = Main(20, 20, 0, 1, 4, [rec])
    m.run()
