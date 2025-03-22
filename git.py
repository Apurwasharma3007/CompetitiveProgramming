import os
from random import randint, random

for i in range(1, 360):
    if random() < 0.7:  # 70% chance to commit, 30% chance to skip the day
        for j in range(randint(1, 6)):
            d = str(i) + ' days ago'
            with open('file.txt', 'a') as file:
                file.write(d + '\n')  # Ensure new line for readability
            os.system('git add .')
            os.system('git commit --date="' + d + '" -m "latest commit"')

os.system('git push -u origin main')
