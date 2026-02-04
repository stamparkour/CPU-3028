# Contributing Guidelines

If you with to contribute to this project, please follow the guidelines below.

## Table of Contents

## Style Guide

This section is dedicated to ensuring a consistent style throughout the project. 
All style guidelines should be used, but in justified situtations they may be broken.

### Naming

All classes, variables, methods, constants, namespaces, and header files should use snake_casing.

*Example*

	my_type_t my_function(int my_variable);

The only exception to this rule is template parameters. 
All template parameters should be in CamelCase with reasonably short names. 

*Example*

	template<typename ValT, typename... ParT>

#### Adendum

Within a templated class, all template parameters should be held in typedefs or constexpr statements.

### Bracing

For all code blocks (function body, if body, etc), the opening curly brace should be on the same line as the keyword. 
The closing curly brace should always be on its own line or merged with other closing curly braces.

*Example*

	if( a == b ) {
		// code block
	}
	else {
		// another code block
	}

For C-style object declarations, you may keep everything on the same line or adhere to the code block standard.

*Example*

	