# Writeup for `Way home`

| author | category | value |
|--------|----------|-------|
| Jason  |  recon   |  100  |

This is my first time taking public transport but I don’t know which bus will take me home! I took a photo of the bus but some key information is missing 😔. Can you tell me the route number and name so I can get home safe?
*Note*: Your answer should be the bus route of the bus in the picture, you do not need to wrap your answer with `RCR{}`. For example, if you think the route is 373, then supply `373` as the flag.


| cost |      content      |
|------|-------------------|
|  0   | Try Google images |

## Files

- [src/challenge.jpg](src/challenge.jpg): An image of a bus with the route number censored.

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

Doing a Google reverse image search shows the exact picture here: https://www.abc.net.au/news/2023-08-09/u-go-mobility-apologises-poor-bus-services-sydney-south/102706652

An alternative method involves looking up the bus number "6952" (e.g. something like `Sydney "6952" bus`) which should reveal the bus is associated with the location "Menai" (e.g. https://fleetlists.busaustralia.com/tdv.php?search=TDV&ltype=old) Looking up bus routes reveals only a handful of buses travel through this area (also note that the bus itself is used for different routes): https://moovitapp.com/index/en-gb/public_transportation-Menai-Sydney-city_33192-442/ and at this point you could just bruteforce :P

### Walkthrough

(instructions may change in coming years if Google changes their UI :P)
1. Go to https://images.google.com/ .
2. Click the "Search by image icon" on the right-most side of the search bar.
3. Copy the image and paste it into the field.
4. The first result (or at least one of) should show this news article, which has the bus number in the picture: https://www.abc.net.au/news/2023-08-09/u-go-mobility-apologises-poor-bus-services-sydney-south/102706652



### Flag(s)

- `961`

</details>
