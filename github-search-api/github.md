#Description
Luke Skywalker can destroy the Death Star only if he can find the particular issues in the source code of the control system, which is deployed on Death Star. His mentor, Obi-Wan Kenobi has given him the date on which those issues were created. Luke doesn't have any clue about programming and has asked you to help him. The source code of Death Star's control system is hosted on Github.
Given the organization, the repository and the date, output the list of urls of issues/pull requests created on that date.
Reference: https://developer.github.com/v3/
Note: The script will run in Linux environment with root access and internet connectivity.
#Input
A single line containing the organization name, the repository name and the date in DD-MM-YYYY format.
#Output
n lines each containing a URL of a issue/pull request. The URLs should be listed in the ascending order of time when the issue/pull request was created
#Sample Input
atom atom 27-02-2013
#Sample Output
https://github.com/atom/atom/pull/314
https://github.com/atom/atom/issues/315
https://github.com/atom/atom/pull/316
https://github.com/atom/atom/pull/317
https://github.com/atom/atom/pull/318
https://github.com/atom/atom/pull/319
https://github.com/atom/atom/issues/320
