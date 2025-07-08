# Writeup for `Election`

|  author  | category | value |
|----------|----------|-------|
| Ixbixbam |  recon   |  100  |

I saw that one of my friends posted online saying that "I can't believe my preferences align so closely with everyone else in Tasmania in this year's federal vote for the senate! My first 6 preferences completely aligned with the parties with the highest first preferences. I can't believe so many Tasmanians voted for Clive Palmers party though, my 7th preference was the shooters party."
He cares about not sharing too much information online, but I'm worried he doesn't know that it is possible to view votes in many Australian elections with their vote location. What is the postcode of the polling place the friend voted at?
**Note:** Your answer should be the postcode of the polling place the friend voted, you do not need to wrap your answer with `RCR{}`. For example, if you think the vote collection point is 2052, then supply `2052` as the flag.


| cost |                                                                             content                                                                              |
|------|------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|  0   | Try researching and downloading files with Tasmania's formal preferences in the 2025 federal senate election and filtering the votes based on the friend's post. |

## Solution

<details>
<summary>Click here to reveal the solution!</summary>

### The Big Idea

It turns out everybody's (anonymised) votes are posted online *with the polling booth listed* O_O. I'm sure this could reveal no personal information about individuals :D.

Anyway, if we navigate to the AEC website and download a CSV of the first preference senate votes for Tasmania in 2025, cross verifying it with the top 6 first preferences in Tasmania, we can find a vote entry whose top 6 matches these preferences and 7th is the Shooters party (as per the challenge description of this supposed friend).

### Walkthrough

1. Download the Formal preferences votes for the senate in Tasmania on this page: https://results.aec.gov.au/31496/Website/SenateDownloadsMenu-31496-Csv.htm
2. Note the top 6 parties here: https://results.aec.gov.au/31496/Website/SenateStateFirstPrefsByGroup-31496-TAS.htm
3. Find a vote entry in the CSV which has `Australian Labor Party, Liberal, The Greens, Jacqui Lambie Network, Pauline Hanson's One Nation, Legalise Cannabis Party, Shooters, Fishers and Farmers Party` as the numbered preferences.
4. Find that the polling booth was in Kingston, Franklin, which has postcode `7050`.

[solution.py](solution.py) has a detailed script to search the AEC CSV of votes.

### Flag(s)

- `7050`

</details>
