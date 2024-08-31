execute as @a at @s if block ~ ~-1 ~ anvil run effect give @a glowing 1000 1 false
scoreboard objectives add asdf dummy 
execute as @a[name=!"민철"] run scoreboard players add @s asdf 100
execute as @a if score @s asdf matches 0 run kill @s 

execute as @e[type=pig] as @s run summon dolphin ~ ~10 ~ {NoAI:1}
execute as @a[name=rascal050902] as @s run tellraw @s "니 알빠가 아닌"