# Writeup for `Notangles 2`

|     author     | category | value |
|----------------|----------|-------|
| Notangles-team |   web    |  100  |

The Notangles team is being extra secretive about new updates coming in T2. They have been hurredily testing some changes on their staging instance. You wonder if they left any secrets lying around whilst testing - surely data on their **accounts** would be impossible to reach right? 🤔 Through a bit of OSINT, you find one of the director's zID - z5476247, probably worth noting down for later...
**Note:** Since this is not the live version of Notangles, you do not need to worry about accidently viewing private data. It is not necessary to use brute force, but you may attempt to actively exploit the application. Obviously, please do not investigate the live version of Notangles.


## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

# Clues
The Notangles team is being extra secretive about new updates coming in T2. They have been hurredily testing some changes on their staging instance (https://notanglesctf.devsoc.app). You wonder if they left any secrets lying around whilst testing - surely data on their **accounts** would be impossible to reach right? 🤔 Through a bit of OSINT, you find one of the director's zID - z5476247, probably worth noting down for later...

# Solution
Simplest is visiting https://notanglesctf.devsoc.app/api/user/profile/z5476247 and CTRL+F for RCR. Intended solution is discovering that despite implementing authentication via zID, there is no authorization, and most routes allow for providing specific zIDs or timetable IDs. It is possible to construct a longer attack through chaining requests (looking for a list of timetables, then events in timetables, then looking up an event) if a student does not realise the flag is already available in the basic profile request already. Flag is `RCR{4u7h3n71c4710n_v5_4u7h0r1z4710n}`

### Walkthrough

As above.

### Flag(s)

- `RCR{4u7h3n71c4710n_v5_4u7h0r1z4710n}`

</details>
