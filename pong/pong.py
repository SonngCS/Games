import pygame
from paddle import Paddle
from ball import Ball

#initiating and defining the colors
pygame.init()
black = (0, 0, 0)
green = (0, 255, 0)
white = (255, 255, 255)

#making the screen
size = (700, 500)
screen = pygame.display.set_mode(size)
pygame.display.set_caption("Pong")

#Control variable for the main loop in our game
gameOver = False
scoreA = 0
scoreB = 0

clock = pygame.time.Clock()

paddleA = Paddle(white, 10, 100)
paddleA.rect.x = 20
paddleA.rect.y = 200

paddleB = Paddle(white, 10, 100)
paddleB.rect.x = 670
paddleB.rect.y = 200

ball = Ball(white,10,10)
ball.rect.x = 345
ball.rect.y = 195

all_sprites_list = pygame.sprite.Group()

all_sprites_list.add(paddleA)
all_sprites_list.add(paddleB)
all_sprites_list.add(ball)

while not gameOver:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            gameOver = True
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                gameOver = True
    
    keys = pygame.key.get_pressed()
    if keys[pygame.K_w]:
        paddleA.moveUp(5)
    if keys[pygame.K_s]:
        paddleA.moveDown(5)
    if keys[pygame.K_UP]:
        paddleB.moveUp(5)
    if keys[pygame.K_DOWN]:
        paddleB.moveDown(5)

    all_sprites_list.update()

    if ball.rect.x>=690:
        scoreA+=1
        ball.velocity[0] = -ball.velocity[0]
    if ball.rect.x<=0:
        scoreB+=1
        ball.velocity[0] = -ball.velocity[0]
    if ball.rect.y>490:
        ball.velocity[1] = -ball.velocity[1]
    if ball.rect.y<0:
        ball.velocity[1] = -ball.velocity[1]    

    if pygame.sprite.collide_mask(ball, paddleA) or pygame.sprite.collide_mask(ball, paddleB):
      ball.bounce()

    screen.fill(black)

    pygame.draw.line(screen, white, [349, 0], [349, 500], 5)
    all_sprites_list.draw(screen)

    font = pygame.font.Font(None, 74)
    text = font.render(str(scoreA), 1, white)
    screen.blit(text, (250,10))
    text = font.render(str(scoreB), 1, white)
    screen.blit(text, (420,10))

    pygame.display.flip()

    clock.tick(60)

pygame.quit()

