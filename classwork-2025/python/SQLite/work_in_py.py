import requests
import time

def res():
    requests.get('https://roblox.com/')


def run():
    while True:
        res()

run()