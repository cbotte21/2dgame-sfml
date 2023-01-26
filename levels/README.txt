How to design a level.

1) Create a textfile in this directory.
2) Create map as follows...
3) ./2dgame-sfml <mapname>.txt

RULES:
	- Each map can only have 1 player (denoted by first line)
	- level is rendered first, and dosnt interact. ex) background
	- barriers are rendered next, they are objects a player can not pass through.
	- finally entities are rendered. They can be picked up by a player.

HERES HOW... (first line of text file two below)

<playername> x y
design:
	[<dynamicSprite_name> x y]
barriers:
	[<dynamicSprite_name> x y]
entities:
	[<dynamicSprite_name> x y]