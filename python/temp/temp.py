import turtle

def name():
    # Set up the turtle screen
    turtle.setup(800, 600)
    screen = turtle.Screen()
    screen.title("Turtle Drawing of Chinese Character")
    
    # Create a turtle object
    t = turtle.Turtle()
    t.speed(5)  # Set drawing speed
    
    # Start drawing the character
    t.penup()
    t.goto(-100, 100)  # Starting position
    t.pendown()
    
    # Draw the first part (top square)
    for _ in range(4):
        t.forward(100)
        t.right(90)
    
    # Move to the position for the second part (bottom strokes)
    t.penup()
    t.forward(50)
    t.left(90)
    t.forward(50)
    t.pendown()
    t.right(180)
    t.forward(100)
    t.penup()
    t.right(90)
    t.forward(50)
    t.right(180)
    t.pendown()
    t.forward(100)
    t.penup()
    t.left(180)
    t.forward(50)
    t.left(90)
    t.pendown()
    t.forward(110)
    # Draw a small circle
    t.circle(50, 90)
    t.forward(100)
    t.left(90)
    t.forward(40)
    t.penup()
    # End drawing
    t.hideturtle()
    screen.mainloop()

name()
