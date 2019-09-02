
class Rectangle():

    def __init__(self, m, w, h, x, y, vx, vy):
        self.x = x
        self.y = y
        self.vx = vx
        self.vy = vy
        self.m = m
        self.h = h
        self.w = w
        self.g = 9.8
        self.collided = False

    def update(self, mud, dt, w, h):
        self.updateVelocity(mud, dt)
        self.moveX(w,dt)
        self.moveY(h,dt)
        self.collided = False

    def moveX(self, w,dt):
        self.x += self.vx*dt
        if self.x <= 0 or self.x + self.w >= w:
            self.vx = -self.vx

    def moveY(self, h,dt):
        self.y += self.vy*dt
        if self.y - self.h <= 0 or self.y >= h:
            self.vy = -self.vy

    def checkCollision(self, rec):

        if not self.collided:
            if (self.x <= rec.x <= self.x + self.w) and (self.y >= rec.y >= self.y - self.h):
                vrx = self.vx - rec.vx
                vry = self.vy - rec.vy

                self.vx = vrx*(self.m - rec.m)/(self.m + rec.m)
                self.vy = vry*(self.m - rec.m)/(self.m + rec.m)

                rec.vx = 2*vrx*self.m/(self.m + rec.m)
                rec.vy = 2*vry*self.m/(self.m + rec.m)
                self.collided = True
                rec.collided = True

            elif (self.x <= rec.x <= self.x + self.w) and (self.y >= rec.y - rec.h >= self.y - self.h):
                vrx = self.vx - rec.vx
                vry = self.vy - rec.vy

                self.vx = vrx*(self.m - rec.m)/(self.m + rec.m)
                self.vy = vry*(self.m - rec.m)/(self.m + rec.m)

                rec.vx = 2*vrx*self.m/(self.m + rec.m)
                rec.vy = 2*vry*self.m/(self.m + rec.m)
                self.collided = True
                rec.collided = True
            
            elif (self.x <= rec.x + rec.w <= self.x + self.w) and (self.y >= rec.y - rec.h >= self.y - self.h):
                vrx = self.vx - rec.vx
                vry = self.vy - rec.vy

                self.vx = vrx*(self.m - rec.m)/(self.m + rec.m)
                self.vy = vry*(self.m - rec.m)/(self.m + rec.m)

                rec.vx = 2*vrx*self.m/(self.m + rec.m)
                rec.vy = 2*vry*self.m/(self.m + rec.m)
                self.collided = True
                rec.collided = True

            elif (self.x <= rec.x + rec.w <= self.x + self.w) and (self.y >= rec.y >= self.y - self.h):
                vrx = self.vx - rec.vx
                vry = self.vy - rec.vy

                self.vx = vrx*(self.m - rec.m)/(self.m + rec.m)
                self.vy = vry*(self.m - rec.m)/(self.m + rec.m)

                rec.vx = 2*vrx*self.m/(self.m + rec.m)
                rec.vy = 2*vry*self.m/(self.m + rec.m)
                self.collided = True
                rec.collided = True

        return rec

    def updateVelocity(self, mud, dt):
        if self.vx != 0:
            self.vx -= self.g*mud*dt
        if self.vy != 0:
            self.vy -= self.g*mud*dt

    def isStopped(self):
        if (self.vx**2 + self.vy**2)**(1/2) < 0.0001:
            return True
        return False