<?
//������Ʒ���ƶ�Ӧ�� *********************************************************************
$item_info = explode("_",$item);
$item_type = strtoupper($item_info[0]);   //���ⱦ����̬, ��: MJ �齫��,PK �˿˹�
$item_kind = strtoupper($item_info[1]);   //���ⱦ������, ��: money ���,medal ѫ��
$item_detail = $item_info[2]; //���ⱦ������, ��: 1000 (�������)

switch (strtoupper($item_type)){
  case "DDZ":
       $show_item_name = "Ϸ�ȶ�����";
       break;
  case "DR":
       $show_item_name = "����";
       break;
  default:
       $show_item_name = "��Ʒ����";
       break;
}

switch (strtoupper($item_kind)){
  case "MONEY":
       $show_item_name .= "���".$item_detail."ö";
       break;
  case "MEDAL":
      case "MEDAL":
       if (strtoupper($item_type)=="DDZ"){
          $show_item_name .= "����";
       } else {
          $show_item_name .= "����";
       }

       break;
  case "CLOSET-CLOTHES":
       $show_item_name = "Ϸ�����ֹ��·�+�¹�";
       break;
  case "ITEM":
       $show_item_name .= "���ⱦ��";
       break;
  default:
       $show_item_name = "��Ʒ����";
       break;
}

$arr_item_dr = array(array("id"=>1,"no"=>"9061","name"=>"�����ָ"),
		array("id"=>2,"no"=>"9086","name"=>"��������"),
		array("id"=>3,"no"=>"3025","name"=>"����"),
		array("id"=>4,"no"=>"3015","name"=>"ţ��"),
		array("id"=>5,"no"=>"1046","name"=>"���"),
		array("id"=>6,"no"=>"1047","name"=>"ף��֮Ҷ"),
		array("id"=>7,"no"=>"10064","name"=>"��ħ������"),
		array("id"=>8,"no"=>"8014","name"=>"ܛñ"),
		array("id"=>9,"no"=>"8008","name"=>"�pƤ��"),
		array("id"=>10,"no"=>"8092","name"=>"Ь"),
		array("id"=>11,"no"=>"10223","name"=>"���һǧ��Cell��ծȯ"),
		array("id"=>12,"no"=>"9089","name"=>"��֮��"),
		array("id"=>13,"no"=>"9021","name"=>"ʩĽ�ݰ�֮�I"),
		array("id"=>14,"no"=>"9064","name"=>"�`���ָ"),
		array("id"=>15,"no"=>"10171","name"=>"����"),
		array("id"=>16,"no"=>"10226","name"=>"��ɽѩ�˵�Ƥ��"),
		array("id"=>17,"no"=>"10228","name"=>"��ɽĸѩ�˵�Ƥ��"),
		array("id"=>18,"no"=>"10224","name"=>"��������Cell��ծȯ"),
		array("id"=>19,"no"=>"10236","name"=>"����ĥ��"),
		array("id"=>20,"no"=>"10237","name"=>"���۹ֵ�����"),
		array("id"=>21,"no"=>"8041","name"=>"�R��"),
		array("id"=>22,"no"=>"10223","name"=>"���һǧ��Cell��ծȯ"),
		array("id"=>23,"no"=>"1046","name"=>"���"),
		array("id"=>24,"no"=>"4028","name"=>"����֮ʯ"),
		array("id"=>25,"no"=>"9042","name"=>"�ʴȵČ�ʯ��"),
		array("id"=>26,"no"=>"1022","name"=>"��ʯ"),
		array("id"=>27,"no"=>"10073","name"=>"������������"),
		array("id"=>28,"no"=>"10075","name"=>"��������Ƭ"),
		array("id"=>29,"no"=>"10297","name"=>"���"),
		array("id"=>30,"no"=>"9031","name"=>"����Ů��֮��"),
		array("id"=>31,"no"=>"8043","name"=>"���T֮��"),
		array("id"=>32,"no"=>"10197","name"=>"�ҳ�֮��"),
		array("id"=>33,"no"=>"10170","name"=>"����"),
		array("id"=>34,"no"=>"8144","name"=>"�{���L"),
		array("id"=>35,"no"=>"8039","name"=>"Ӣ�����L"), 
		array("id"=>36,"no"=>"8026","name"=>"�t�����L"),
		array("id"=>37,"no"=>"10119","name"=>"�´����"),
		array("id"=>38,"no"=>"10120","name"=>"�´�����"),
		array("id"=>39,"no"=>"10295","name"=>"�һ���"),
		array("id"=>40,"no"=>"10142","name"=>"��������״"),
		array("id"=>41,"no"=>"10156","name"=>"�����ܳ�"),
		array("id"=>42,"no"=>"10296","name"=>"��������ȯ"),
		array("id"=>43,"no"=>"10291","name"=>"��Ч����ɼ�ȯ"),
		array("id"=>44,"no"=>"8304","name"=>"������֮��"),
		array("id"=>45,"no"=>"8305","name"=>"������֮��ñ"),
		array("id"=>46,"no"=>"8306","name"=>"������֮Ь"),
		array("id"=>47,"no"=>"8307","name"=>"�Ƿ��ε�֮Ь"),
		array("id"=>48,"no"=>"8308","name"=>"�Ƿ��ε�֮��"),
		array("id"=>49,"no"=>"8309","name"=>"�Ƿ��ε�֮ñ"),
		array("id"=>50,"no"=>"8310","name"=>"������֮����"),
		array("id"=>51,"no"=>"8311","name"=>"����֮��"),
		array("id"=>52,"no"=>"8312","name"=>"����֮ñ"),
		array("id"=>53,"no"=>"8313","name"=>"����֮Ь"),
		array("id"=>54,"no"=>"8314","name"=>"������֮ñ"),
		array("id"=>55,"no"=>"8315","name"=>"������֮Ь"),
		array("id"=>56,"no"=>"8316","name"=>"��ɭս��"),
		array("id"=>57,"no"=>"8317","name"=>"��ɭս��"),
		array("id"=>58,"no"=>"8318","name"=>"��ɭսѥ"),
		array("id"=>59,"no"=>"10294","name"=>"����"),
		array("id"=>60,"no"=>"9116","name"=>"����֮��"),
		array("id"=>61,"no"=>"9121","name"=>"����"),
		array("id"=>62,"no"=>"10292","name"=>"��ķ���صĽ�"),
		array("id"=>63,"no"=>"10293","name"=>"תְ�����"), 
	      );

if ((strtoupper($item_type) == "DR") && (strtoupper($item_kind) == "ITEM")) {
   $item_index = $item_detail-1;
   $show_item_no = $arr_item_dr[$item_index]["no"];
   $show_item_name .= "[". $arr_item_dr[$item_index]["name"] ."]";
}

?>