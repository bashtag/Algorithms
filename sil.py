import os

class Modification:

	PATH = os.getcwd()

	def __init__(self):
		self.getFilePaths()

	def getFilePaths(self):

		c_name_list = os.walk(f"{self.PATH}").__next__()[2]

		for name in c_name_list:
			if ".c" in name:
				self.changeTheHeader(self.PATH + "/" + name)
			

	def	changeTheHeader(self, file_path):
		with open(file_path, "r+", encoding="utf8") as file:
			file.write("/* ************************************************************************** */\n"
					"/*                                                                            */\n"
					"/*                                                        :::      ::::::::   */\n"
					"/*                                                      :+:      :+:    :+:   */\n"
					"/*                                                    +:+ +:+         +:+     */\n"
					"/*   By: bgokce <bgokce@student.42kocaeli.com.tr    +#+  +:+       +#+        */\n"
					"/*                                                +#+#+#+#+#+   +#+           */\n"
					"/*   Created: 2022/10/03 14:33:20 by bgokce            #+#    #+#             */\n"
					"/*   Updated: 2022/10/03 14:37:13 by bgokce           ###   ########.fr       */\n"
					"/*                                                                            */\n"
					"/* ************************************************************************** */")

app = Modification()