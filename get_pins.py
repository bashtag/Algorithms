# not working yet

global psbl_str
psbl_str = ""

def rec_getpins(ob, psbl_0):
	psbl_str += psbl_0[ob[0]]
	rec_getpins(ob[1:], psbl_0)




def get_pins(observed):
	psbl_list = []

	psbl_0 = [["0", "8", "", "", ""],
			["1", "2", "4", "", ""],
			["1", "2", "3", "5", ""],
			["2", "3", "6", "", ""],
			["1", "4", "5", "7", ""],
			["2", "4", "5", "6", "8"],
			["3", "5", "6", "9", ""],
			["4", "7", "8", "", ""],
			["0", "5", "7", "8", "9"],
			["6", "8", "9", "", ""]]

	rec_getpins(observed, psbl_0)




print("bilal"[1:])
