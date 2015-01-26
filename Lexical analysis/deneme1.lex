
 Keyword (PROGRAM) 	Identifier (MAIN) 	
 Keyword (INTEGER) 	Identifier (N) 	Symbol (,) 	Identifier (X) 	
 Keyword (EXTERNAL) 	Identifier (SUB1) 	
 Keyword (COMMON) 	Symbol (/)	Identifier (GLOBALS)	Symbol (/)	Identifier (N) 	Identifier (X) 	AssignmentOp 	ConstantNumber ( 0) 	
 Keyword (PRINT) 	Asteriks 	Symbol (,) 	Symbol ( ' )	String (Enter number of repeats)	Symbol( ' )
 Keyword (READ) 	LeftParan 	Asteriks 	Symbol (,) 	Asteriks 	RightParan 	Identifier (N) 	
 Keyword (CALL) 	Identifier (SUB1) 	LeftParan 	Identifier (X) 	Symbol (,) 	Identifier (SUB1) 	RightParan 	
 Keyword (END) 	
 Keyword (SUBROUTINE) 	Identifier (SUB1) 	LeftParan 	Identifier (X) 	Symbol (,) 	Identifier (DUMSUB) 	RightParan 	
 Keyword (INTEGER) 	Identifier (N) 	Symbol (,) 	Identifier (X) 	Symbol (,) 	Identifier (Y) 	
 Keyword (EXTERNAL) 	Identifier (DUMSUB) 	
 Keyword (COMMON) 	Symbol (/)	Identifier (GLOBALS)	Symbol (/)	Identifier (N) 	
 Keyword (DATA) 	Identifier (Y) 	Symbol (/)	ConstantNumber (0) 	Symbol (/)	
 Keyword (IF) 	LeftParan 	Identifier (X) 	LessThanOp 	Identifier (N) 	RightParan 	
 Keyword (THEN) 	Identifier (X) 	AssignmentOp 	Identifier (X) 	Add 	ConstantNumber ( 1) 	Identifier (Y) 	AssignmentOp 	Identifier (Y) 	Add 	ConstantNumber ( 1) 	
 Keyword (PRINT) 	Asteriks 	Symbol (,) 	Symbol ( ' )	String (x = )	Symbol( ' )Symbol (,) 	Identifier (X) 	Symbol (,) 	Symbol ( ' )	String (, y = )	Symbol( ' )Symbol (,) 	Identifier (Y) 	
 Keyword (CALL) 	Identifier (DUMSUB) 	LeftParan 	Identifier (X) 	Symbol (,) 	Identifier (DUMSUB) 	RightParan 	
 Keyword (END) 	
 Keyword (IF) 	
 Keyword (END) 	