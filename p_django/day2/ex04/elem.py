#!/usr/bin/python3

class Text(str):
	"""
	A Text class to represent a text you could use with your HTML elements.

	Because directly using str class was too mainstream.
	"""

	def __str__(self):
		"""
		Do you really need a comment to understand this method?..
		"""
		return super().__str__().replace('<', '&lt;').replace('>', '&gt;').replace('"', '&quot;').replace('\n', '\n<br />\n')


class Elem:
	"""
	Elem will permit us to represent our HTML elements.
	"""
	class ValidationError(Exception):
		def __init__(self) -> None:
			super().__init__("ValidationError")

	def __init__(self, tag='div', attr={}, content=None, tag_type='double'):
		"""
		__init__() method.
		Obviously.
		"""
		[...]
		self.tag = tag
		self.attr = attr
		self.content = []
		if not self.check_type(content) and content is not None:
			raise self.ValidationError
		if type(content) == list:
			self.content = content
		elif content is not None:
			self.content.append(content)

		# self.content = []
			# self.add_content(content)
		self.tag_type = tag_type
		# if type(content) is list :
			# print(content)

	def __str__(self):
		"""
		The __str__() method will permit us to make a plain HTML representation
		of our elements.
		Make sure it renders everything (tag, attributes, embedded
		elements...).
		"""
		attr = self.__make_attr()
		result = ''
		if self.tag_type == 'double':
			[...]
			result += "<{tag}{attr}>>".format(tag=self.tag, attr=attr)
			result += "{content}</{tag}>".format(content=self.__make_content(), tag=self.tag)
		elif self.tag_type == 'simple':
			result += "<{tag}{attr}/>".format(tag=self.tag, attr=attr)
		return result

	def __str__(self):
		attr = self.__make_attr()
		result = "<{tag}{attr}".format(tag=self.tag, attr=attr)
		if self.tag_type == 'double':
			result += ">{content}</{tag}>".format(content=self.__make_content(), tag=self.tag)
		elif self.tag_type == 'simple':
			result += "/>"
		return result

	def __make_attr(self):
		"""
		Here is a function to render our elements attributes.
		"""
		result = ''
		for pair in sorted(self.attr.items()):
			result += ' ' + str(pair[0]) + '="' + str(pair[1]) + '"'
		return result

	def __make_content(self):
		if len(self.content) == 0:
			return ""
		result = "\n"
		for elem in self.content:
			if (len(str(elem)) != 0):
				result += "{elem}\n".format(elem=elem)
		result = "  ".join(line for line in result.splitlines(True))
		if len(result.strip()) == 0:
			return ''
		return result

	def add_content(self, content):
		if not Elem.check_type(content):
			raise Elem.ValidationError
		if type(content) == list:
			self.content += [elem for elem in content if elem != Text('')]
		elif content != Text(''):
			self.content.append(content)

	@staticmethod
	def check_type(content):
		"""
		Is this object a HTML-compatible Text instance or a Elem, or even a
		list of both?
		"""
		return (isinstance(content, Elem) or type(content) == Text or
				(type(content) == list and all([type(elem) == Text or
												isinstance(elem, Elem)
												for elem in content])))


if __name__ == '__main__':
	try:
		Elem(content=1)
	except Exception as e:
		assert type(e) == Elem.ValidationError