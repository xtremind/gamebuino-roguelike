# Creating a roguelike

https://www.youtube.com/watch?v=HnY7Inp74dw&list=TLPQMzEwNTIwMjJoeOrm41Og6A&index=3&ab_channel=LazyDevs

## Statements

- light color when interaction is possible
- dark color when no interaction
- no diagonal movement

## tasks

### Step 1 : basic movement

- [ ] TILES : draw character (4 frames to animate, with up/down head animation)
- [ ] TILES : draw ground tile (simple dot at center to help know the space for each room)
- [ ] TILES : draw wall tile (brick like)
- [ ] TILES : draw down stair tile
- [ ] TILES : draw up stair tile
- [ ] STAGE : define the stages of your game (START, GAME, GAMEOVER)
- [ ] STAGE : display a empty screen with a specific color
- [ ] TILESET : draw a first map/level
- [ ] DRAW GAME : display the first map/level
- [ ] DRAW GAME : display one frame of the character
- [ ] UPDATE GAME : move the character in four directions one case at a time
- [ ] DRAW GAME : change color of the character from grey to yellow

([video](https://youtu.be/SoFOva5FUnI) / [code](pico8/01_basic_movement.lua))

### Step 2 : animate character, and allow move between case

- [ ] ANIMATION : hero
- [ ] REFACTO : compute next frame for error depending of frameCount from list of sprites of object(hero)
- [ ] REFACTO : draw element from sprite, position and color
- [ ] STAGE : create new stage for compute movement between 2 cases (PTURN)
- [ ] UPDATE GAME : add an offset (x/y) of 8 pixels, depending of direction
- [ ] UPDATE GAME : if offset > 0, then go, to stage PTURN
- [ ] UPDATE PTURN : reduce offset from value to 0
- [ ] UPDATE PTURN : if offset = 0, then go, to stage GAME

([video](https://youtu.be/CO1qTJMH8mU) / [code](pico8/02_animation.lua))

### Step 3 : Token optimization

- [ ] HERO : create tables with value depending of directions
- [ ] HERO : create a function move that take into account a direction pressed
- [ ] UPDATE GAME : change method by calling move hero with direction
- [ ] HERO : create a timer variable
- [ ] HERO : create starting offset variables
- [ ] UPDATE depending : the timer is equal the minimum between itself + value and 1
- [ ] UPDATE depending : update current offset with starting offset and timer
- [ ] UPDATE depending : if timer is equals to one, to stage GAME
- [ ] CONFIG : change framerate to 60 ???

([video](https://youtu.be/1ZUhxXQiDCA) / [code](pico8/03_animation.lua))

### Step 4 : Wall collisions

- [ ] DRAW GAME : draw a flip hero when moving to the left
- [ ] DRAW GAME : an flip hero stay flipped if moving up/down
- [ ] INTERACTION : define which tiles are solid
- [ ] INTERACTION : define next tile
- [ ] INTERACTION : if next tile is solid, don't move
- [ ] INTERACTION : if next tile is solid, add feedback (bump => forward then backward)

([video](https://youtu.be/PnE5S4DoNEg) / [code](pico8/04_wall_collision.lua))

### Step 5 : Object interaction

- [ ] LEVEL DESIGN : create a sort of first level
- [ ] TILES : draw up door tile
- [ ] TILES : draw up closed chest tile
- [ ] TILES : draw up opened chest tile
- [ ] TILES : draw up jar tile
- [ ] TILES : draw up panel tile
- [ ] INTERACTION : update solid tiles with new tiles
- [ ] INTERACTION : define which tiles are interactive
- [ ] LEVEL DESIGN : update first level with all new tiles
- [ ] INTERACTION : when detect bumping, check if expected destination is interactive tiles
- [ ] INTERACTION : when detect bumping into a jar, destroy it
- [ ] INTERACTION : when detect bumping into a closed chest, open it
- [ ] INTERACTION : when detect bumping into a door, destroy it
- [ ] INTERACTION : when detect bumping into a panel, ...
- [ ] UPDATE GAME : add a button buffer, that will contain all pressed buttons (only one more button is enough, since it's a roguelike)
- [ ] UPDATE GAME : from button buffer, move player 

([video](https://youtu.be/y3uNmCL414M) / [code](pico8/05_object_interaction.lua))

### Step 6 : Text Boxes

- [ ] SOUND : create "walking" sound
- [ ] SOUND : create "opening door" sound
- [ ] SOUND : create "opening chest" sound
- [ ] SOUND : create "bad things" sound
- [ ] SOUND : create "breaking vase" sound
- [ ] INTERACTION : add sound effect for each action
- [ ] REFACTO : extract buffer button usage in a function
- [ ] TEXTBOX : create a function that create a text do display
- [ ] TEXTBOX : update previous function by adding the object in a list / array
- [ ] TEXTBOX : create a function that draw a box with border
- [ ] TEXTBOX : update previous function by displaying text
- [ ] TEXTBOX : update previous function by multiple textbox (like multi-tab)

([video](https://youtu.be/6G2StWNTFlo) / [code](pico8/06_text_boxes.lua))

### Step 7 : Messages System

- [ ] INTERACTION : show textbox when interacting with panel
- [ ] TEXTBOX : compute the width of the box containing the message
- [ ] TEXTBOX : centering the textbox
- [ ] TEXTBOX : add space after/before message in textbox
- [ ] TEXTBOX : displayed message disappear after a certain amount of time
- [ ] TEXTBOX : add animation when message disappear (like parchemin is opened)
- [ ] TALK : message without duration, but disappear after button pressed
- [ ] TALK : display button to push to close the textbox on the the bottom right
- [ ] TALK : displayed button move up and down
- [ ] TALK : don't move until talk disappear
- [ ] PANEL : add multiple panel, with different text in it

([video](https://youtu.be/XuT3nwDuRiw) / [code](pico8/07_message_system.lua))

### Step 8 : Monsters

- [ ] TILES : draw a monster : slime (4 frames to animate, with up/down head animation)
- [ ] DRAW GAME : display slime
- [ ] MOB : create a list than contain mobs
- [ ] MOB : create a function to add a mob
- [ ] DRAW GAME : draw mob from list

([video](https://youtu.be/rjWxDQcYUwo) / [code](pico8/08_monsters.lua))

### Step 9 : Mob System

- [ ] CHARACTER : use it to define a mob
- [ ] MOB : create multiple mob
- [ ] MOB : create a function to create a mob on a certain position
- [ ] INTERACTION : create a function to determine if a position is walkable
- [ ] INTERACTION : create a function to determine if a position is in bound
- [ ] INTERACTION : create a function to retreive a mob from a position if existing
- [ ] INTERACTION : do bump when hitting a mob
- [ ] INTERACTION : create a empty function to that will attack a mob
- [ ] GLOBAL : make p_timer a global variable

([video](https://youtu.be/CSIHQElMdF0) / [code](pico8/09_mob_system.lua))

### Step 10 : Combat

- [ ] CHARACTER : add attack / current energy / max energy depending on type
- [ ] INTERACTION : create a function that will reduce the energy from the mob depending of the atteck
- [ ] CHARACTER : create a function that will determine if it's dead (HP <= 0)
- [ ] INTERACTION : create a function that delete a mob if killed
- [ ] INTERACTION : create a function that will change the color of the attacked mob if attacked to white
- [ ] SOUND : create "attack a mob" sound
- [ ] SOUND : create "been hit" sound
- [ ] INTERACTION : create a function that show the reduce of life upper the mob

([video](https://youtu.be/FvSLsmTCIO4) / [code](pico8/10_combat.lua))

### Step 11 : Path Finding

- [ ] MAP : put monster sprite
- [ ] LEVEL : use monster sprite as a mob character generator at the starting game
- [ ] LEVEL : change monster sprite by floor once generated
- [ ] UTILS : create a function that compute distance between 2 points
- [ ] UPDATE : create a function that will loop on all mobs
- [ ] UPDATE : find the lower distance from mob to hero after moving
- [ ] UPDATE : move mob depending on lowest distance
- [ ] UPDATE : create an update mob turn function 
- [ ] UPDATE : call the new function on update mob turn
- [ ] UPDATE : go update mob turn once update player turn is done
- [ ] UPDATE : go update player turn once update mob turn is done
- [ ] UPDATE : verify that the lower distance is walkable
- [ ] UPDATE : if the distance between mob and player is 1, attack player (BUMP + ATTACK), else move to player
- [ ] UPDATE : add sound when been attacked
- [ ] SPRITE : add flashed player sprite

([video](https://youtu.be/qLIPY0ro5UY) / [code](pico8/11_simple_path_finding.lua))

### Step : 

- [ ] 
- [ ] 

([video]() / [code]())

## tools 

- [libresprite - draw in pixel art](https://libresprite.github.io/#!/)
- [example of pixel arts monsters](https://twitter.com/kirai_s/status/812824701533728770)
- 