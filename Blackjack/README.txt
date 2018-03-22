To run after building, please drag all necessary binaries and image resources from the Libraries and BlackjackClient folder into proper build result folder.
Release.zip includes prebuilt with binaries and resources.
Debug/Release x86 profile has included all necessary libraries by default. Make sure you build using a Windows SDK that is installed on your PC.

Notes:
A player will win if their score is exactly 21 at the end of their turn
A player will lose if their score exceeds 21 at the end of their turn
A player will win if their score is exactly 21 at the end of their turn
The bot will hold when its score is >= 17
If both players hold, the player with the highest score (not exceeding 21) will win