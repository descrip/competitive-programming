from PIL import Image, ImageDraw

black = (0,0,0)
white=(255,255,255)
red = (255,0,0)
im = Image.new('RGB', (1000, 1000), white)
imPxAccess = im.load()
draw = ImageDraw.Draw(im)

verts = []
n = int(input())
for i in range(n):
    verts.append(tuple([int(_) for _ in input().split()]))

# either use .polygon(), if you want to fill the area with a solid colour
draw.polygon( verts, outline=black,fill=white )

# or .line() if you want to control the line thickness, or use both methods together!
draw.line( verts+[verts[0]], width=2, fill=black )

for i in range(len(verts)):
    tmp = (verts[i][0] - 5, verts[i][1] - 5, verts[i][0] + 5, verts[i][1] + 5)
    draw.ellipse(tmp, fill=red)

im.show()
