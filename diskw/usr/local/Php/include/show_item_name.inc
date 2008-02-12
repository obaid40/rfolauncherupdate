<?
//虚拟物品名称对应表 *********************************************************************
$item_info = explode("_",$item);
$item_type = strtoupper($item_info[0]);   //虚拟宝物型态, 例: MJ 麻将馆,PK 扑克馆
$item_kind = strtoupper($item_info[1]);   //虚拟宝物种类, 例: money 金币,medal 勋章
$item_detail = $item_info[2]; //虚拟宝物数据, 例: 1000 (金币数量)

switch (strtoupper($item_type)){
  case "DDZ":
       $show_item_name = "戏谷斗地主";
       break;
  case "DR":
       $show_item_name = "龙族";
       break;
  default:
       $show_item_name = "物品不明";
       break;
}

switch (strtoupper($item_kind)){
  case "MONEY":
       $show_item_name .= "金币".$item_detail."枚";
       break;
  case "MEDAL":
      case "MEDAL":
       if (strtoupper($item_type)=="DDZ"){
          $show_item_name .= "锦旗";
       } else {
          $show_item_name .= "锦旗";
       }

       break;
  case "CLOSET-CLOTHES":
       $show_item_name = "戏谷娱乐馆衣服+衣柜";
       break;
  case "ITEM":
       $show_item_name .= "虚拟宝物";
       break;
  default:
       $show_item_name = "物品不明";
       break;
}

$arr_item_dr = array(array("id"=>1,"no"=>"9061","name"=>"神恩戒指"),
		array("id"=>2,"no"=>"9086","name"=>"晨曦项链"),
		array("id"=>3,"no"=>"3025","name"=>"披萨"),
		array("id"=>4,"no"=>"3015","name"=>"牛排"),
		array("id"=>5,"no"=>"1046","name"=>"玛瑙"),
		array("id"=>6,"no"=>"1047","name"=>"祝福之叶"),
		array("id"=>7,"no"=>"10064","name"=>"炎魔的牙齿"),
		array("id"=>8,"no"=>"8014","name"=>"軟帽"),
		array("id"=>9,"no"=>"8008","name"=>"輕皮甲"),
		array("id"=>10,"no"=>"8092","name"=>"鞋"),
		array("id"=>11,"no"=>"10223","name"=>"面额一千万Cell的债券"),
		array("id"=>12,"no"=>"9089","name"=>"星之冠"),
		array("id"=>13,"no"=>"9021","name"=>"施慕妮安之淚"),
		array("id"=>14,"no"=>"9064","name"=>"靈魂戒指"),
		array("id"=>15,"no"=>"10171","name"=>"兔子"),
		array("id"=>16,"no"=>"10226","name"=>"高山雪人的皮革"),
		array("id"=>17,"no"=>"10228","name"=>"高山母雪人的皮革"),
		array("id"=>18,"no"=>"10224","name"=>"面额五百万Cell的债券"),
		array("id"=>19,"no"=>"10236","name"=>"神秘磨菇"),
		array("id"=>20,"no"=>"10237","name"=>"百眼怪的牙齿"),
		array("id"=>21,"no"=>"8041","name"=>"馬鞍"),
		array("id"=>22,"no"=>"10223","name"=>"面额一千万Cell的债券"),
		array("id"=>23,"no"=>"1046","name"=>"玛瑙"),
		array("id"=>24,"no"=>"4028","name"=>"极限之石"),
		array("id"=>25,"no"=>"9042","name"=>"仁慈的寶石盒"),
		array("id"=>26,"no"=>"1022","name"=>"钻石"),
		array("id"=>27,"no"=>"10073","name"=>"大巫妖的眼球"),
		array("id"=>28,"no"=>"10075","name"=>"红龙的鳞片"),
		array("id"=>29,"no"=>"10297","name"=>"金币"),
		array("id"=>30,"no"=>"9031","name"=>"妖精女王之戒"),
		array("id"=>31,"no"=>"8043","name"=>"幻騎之鞍"),
		array("id"=>32,"no"=>"10197","name"=>"忠诚之戒"),
		array("id"=>33,"no"=>"10170","name"=>"玉兔"),
		array("id"=>34,"no"=>"8144","name"=>"藍披風"),
		array("id"=>35,"no"=>"8039","name"=>"英雄披風"), 
		array("id"=>36,"no"=>"8026","name"=>"賢者披風"),
		array("id"=>37,"no"=>"10119","name"=>"新春红包"),
		array("id"=>38,"no"=>"10120","name"=>"新春爆竹"),
		array("id"=>39,"no"=>"10295","name"=>"兑换卷"),
		array("id"=>40,"no"=>"10142","name"=>"三好生奖状"),
		array("id"=>41,"no"=>"10156","name"=>"银行密匙"),
		array("id"=>42,"no"=>"10296","name"=>"披风幸运券"),
		array("id"=>43,"no"=>"10291","name"=>"无效矿物采集券"),
		array("id"=>44,"no"=>"8304","name"=>"妮莉亚之甲"),
		array("id"=>45,"no"=>"8305","name"=>"妮莉亚之软帽"),
		array("id"=>46,"no"=>"8306","name"=>"妮莉亚之鞋"),
		array("id"=>47,"no"=>"8307","name"=>"亚夫奈德之鞋"),
		array("id"=>48,"no"=>"8308","name"=>"亚夫奈德之袍"),
		array("id"=>49,"no"=>"8309","name"=>"亚夫奈德之帽"),
		array("id"=>50,"no"=>"8310","name"=>"杰伦特之斗蓬"),
		array("id"=>51,"no"=>"8311","name"=>"卡尔之甲"),
		array("id"=>52,"no"=>"8312","name"=>"卡尔之帽"),
		array("id"=>53,"no"=>"8313","name"=>"卡尔之鞋"),
		array("id"=>54,"no"=>"8314","name"=>"杰伦特之帽"),
		array("id"=>55,"no"=>"8315","name"=>"杰伦特之鞋"),
		array("id"=>56,"no"=>"8316","name"=>"衫森战盔"),
		array("id"=>57,"no"=>"8317","name"=>"衫森战铠"),
		array("id"=>58,"no"=>"8318","name"=>"衫森战靴"),
		array("id"=>59,"no"=>"10294","name"=>"精金"),
		array("id"=>60,"no"=>"9116","name"=>"矮人之戒"),
		array("id"=>61,"no"=>"9121","name"=>"名人"),
		array("id"=>62,"no"=>"10292","name"=>"阿姆塔特的剑"),
		array("id"=>63,"no"=>"10293","name"=>"转职任务卷"), 
	      );

if ((strtoupper($item_type) == "DR") && (strtoupper($item_kind) == "ITEM")) {
   $item_index = $item_detail-1;
   $show_item_no = $arr_item_dr[$item_index]["no"];
   $show_item_name .= "[". $arr_item_dr[$item_index]["name"] ."]";
}

?>
