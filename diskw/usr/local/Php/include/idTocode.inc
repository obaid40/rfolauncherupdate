<?
	function randomletter()
	{
		$letterlist = array("A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z");
		srand((double)microtime()*1000000);
		$index = rand(0,count($letterlist)-1);
		return $letterlist[$index];
	}

	function findcode($conn)
	{
		
	}
?>