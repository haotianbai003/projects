Proof of concept for using the Ontario 511 API.

Originally supposed to be a part of a larger project that will help with my dad's commutes. Google Maps doesn't show future planned overnight closures/roadworks. The code was supposed to eventually be ran on a raspberry pi and send text notification to him to alert him of the state of HWY 401. 

Unfortunately, the API was less than satisfactory. The secondary long/latitudes of reports are never used (meaning a closure from HWY 404 to Yonge St. on HWY 401 WEST, for example, will only have the coordinate for HWY 404) and the results are not reliable. Project never made it pass the prototype stage.
