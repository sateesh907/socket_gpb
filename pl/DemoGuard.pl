use warnings;

use Spreadsheet::ParseExcel;
use Spreadsheet::BasicRead;

use Cwd;
use Cwd 'abs_path';
use File::Basename;
use 5.010;

# getting the spreadsheet object and using the object reading the row data.

my $read =new Spreadsheet::BasicRead('SampleGuardExpressions.xls');
#my $row=0;
$read->skipHeadings(1);
my $val= $read->getNextRow();

# inserting the data into hash for method names and paramenters

my $parser = Spreadsheet::ParseExcel->new();
my $workbook = $parser->parse('SampleGuardExpressions.xls') or die $parser->error();
my $worksheet = $workbook->worksheet(0);
my ( $row_min , $row_max ) = $worksheet->row_range();


#$self_prog = abs_path($0);
$class_name = "DemoGuard";
$source = 1;
$header = 1;
$query = 1;
$source_file_name = "";
$header_file_name = "";
#&parse_input();
if ($class_name eq "") {
  print("No name given\n");
  exit 1;
}
$project_dir = basename(cwd());

$header_file_name = $class_name . ".h";
$source_file_name = $class_name . ".cpp";
print "the header file is ", $header_file_name,"\n";
print "the source file is ", $source_file_name,"\n";
my @method_names;
my @method_types;
my @data_types;
my @data_values;
my @oprnd_names;
my @Id_names;
my @expression_values;
my %dpid_fuclassid;

if ($query) {
  &query_for_methods();
}

if ($header) {
  &write_top_of_header();
  &write_header_methods();
  &write_bottom_of_header();
}

if ($source) {
  &write_top_of_source();
  &write_source_methods1();
  &write_source_methods11();
  &write_source_methods2();
  &write_source_methods3();
  &write_subscribe_data();
}



#------------------------------------------------------------------------------
sub query_for_methods() {
  print "Inside the Query for method subroutine \n";
    
    for my $row ( $row_min .. $row_max )
    {
    	  my $val1= $read->getNextRow();
		  
   	  my $name = undef;
          if( $val1->[0] ne "")
    	  {	  
   		 push(@Id_names,$val1->[0]);
	         $name = "EvaluateGuard_".$val1->[0];
	
		 $arguments1=$val1->[2];
		 chomp($arguments1);
	         $arguments2=$val1->[3];
   		 chomp($arguments2);
    		 $arguments3=$val1->[4];
		 chomp($arguments3);
	         $arguments4=$val1->[5];
   		 chomp($arguments4);
    		 $arguments5=$val1->[6];
  		 chomp($arguments5);
		 $expression = $val1->[7];
  		 my $arguments;
    		 my $username;
	
		 if( $arguments1 ne "")
    		 {
  		  	$arguments = $arguments1; 
			my @fields = split /_/, $arguments;
			$username = $fields[0];

		   	if( $arguments2 ne "")
  	  		{
				$arguments = join(",",$arguments,$arguments2); 
				my @fields = split /_/, $arguments2;
				$username = join(",",$username,$fields[0]);
				if( $arguments3 ne "")
	    			{
					$arguments = join(",",$arguments,$arguments3);

					my @fields = split /_/, $arguments3;
					$username = join(",",$username,$fields[0]);	

			    		if( $arguments4 ne "")
					{
						$arguments = join(",",$arguments,$arguments4);
						my @fields = split /_/, $arguments4;
						$username = join(",",$username,$fields[0]);

	    					if( $arguments5 ne "")
						{
							$arguments = join(",",$arguments,$arguments5);
							my @fields = split /_/, $arguments5;
							$username = join(",",$username,$fields[0]);

    						}
            				}
        			  }
	  		     }
    			}
     
    
	    		chomp($name);
	                if ($name eq "") {
      				last;
      			}
 	   		
			print "$username\n";
		    	push(@method_names, $name);
		    	push(@data_values, $arguments );
		    	push(@data_types, $username );
		    	push(@expression_values, $expression );
    		}
    	}
}

#------------------------------------------------------------------------------
sub write_top_of_header() {

  $if_def_name = "$class_name" . "_H";
  open (MYFILE, ">", "$header_file_name");
  print(MYFILE "//=============================================================================
// $class_name.h
//
//  <Full description.>
//

#ifndef $if_def_name
#define $if_def_name


// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs, namespaces
// variables: consts, statics, exported variables (declared extern elsewhere)
// local forward function declarations

//=============================================================================

class $class_name 
{

public:

  $class_name();
  // Default constructor.

  ~$class_name();
  // Destructor.

  bool EvaluateGuard(eGuardID guardId);
  
  void InitSubscribeDynamicData();
");
  close (MYFILE);
}

#------------------------------------------------------------------------------
sub write_header_methods() {
  for ($i = 0; $i < scalar(@method_names) ; $i++) {
    open (MYFILE, ">>", "$header_file_name");
    print(MYFILE "
  bool $method_names[$i]();
  // <Description>
  // Precondition:
");
    }
	print(MYFILE "\n  void InitSubscribeDynamicData();\n");
    close (MYFILE);
}

#------------------------------------------------------------------------------
sub write_bottom_of_header() {
  open (MYFILE, ">>", "$header_file_name");
  print(MYFILE "
private:

  // friends
  // functions

  $class_name(const $class_name&);
  // Prohibited copy constructor.

  void operator=(const $class_name&);
  // Prohibited assignment operator.

};

#endif
");
  close(MYFILE);
}

#------------------------------------------------------------------------------
sub write_top_of_source() {
  open (MYFILE, ">", "$source_file_name");
  print(MYFILE "//=============================================================================
//D <One line description>
//
// <Full description.>
//

#include \"$project_dir/$class_name.h\"
#include \"common.h\"
#include \"guards.h\"
#include \"modelcfgif.h\"
// types: classes, enums, typedefs, namespaces
// variables: consts, statics, exported variables (declared extern elsewhere)
// local forward function declarations

//=============================================================================
${class_name}::$class_name()
//
//D Default constructor.
//
{
}

//=============================================================================
${class_name}::~$class_name()
//
//D Destructor.
//
{
}

//=============================================================================
${class_name}::$class_name(const $class_name&)
//
//D Prohibited copy constructor.
//
{
}

//=============================================================================
void ${class_name}::operator=(const $class_name&)
//
//D Prohibited assignment operator.
//
{
}
");
    close (MYFILE);
}

#------------------------------------------------------------------------------
sub write_source_methods1() {
    open (MYFILE, ">>", "$source_file_name");
    print(MYFILE "
//=============================================================================
bool ${class_name}::EvaluateGuard(eGuardID guardId)
{		

 bool result;
switch(guardId)
{

");
close (MYFILE);
}

#------------------------------------------------------------------------------
sub write_source_methods11() {
  for ($i = 0; $i < scalar(@method_names) ; $i++) {
    open (MYFILE, ">>", "$source_file_name");
    print(MYFILE "
	   case $Id_names[$i]:
		   result = $method_names[$i]();
		   break;

");
}
close (MYFILE);
}

#------------------------------------------------------------------------------
sub write_source_methods2() {
    open (MYFILE, ">>", "$source_file_name");
    print(MYFILE "

}
	return result;	
}
");
close (MYFILE);
}

#------------------------------------------------------------------------------
sub write_source_methods3() {
  for ($i = 0; $i < scalar(@method_names) ; $i++) {
    open (MYFILE, ">>", "$source_file_name");

    print(MYFILE "
//=============================================================================
bool ${class_name}::$method_names[$i]()
//
//D <Description>
//
{
	
");
	my @datas1 = split(',',$data_types[$i]);
	print " $data_types[$i] \n";
	my $k = 0;
        my $sub_value;
	foreach my $data2(@datas1)
	{
		print "$data2\n";
		if( $data2 eq "P" )
		{
			$type = "bool";
			$default_value = "false";
		}
		elsif ( $data2 eq "IDPID" )
		{
			$type = "int32_t";
			$default_value = 0;
		}
		elsif ( $data2 eq "FDPID" )
		{
		    $type = "float";
			$default_value = 0;
		}
		elsif ( $data2 eq "SDPID" )
		{
		    $type = "string_t";
		    $default_value = "";
		}
		$sub_value = "oprnd_value_".$k;
		push(@oprnd_names,$sub_value);

    print(MYFILE "
    $type $sub_value = $default_value;
	
");
	$k++;
   	}
		my @datas2 = split(',',$data_values[$i]);
		my $j = 0;
		foreach my $data1(@datas2)
		{	
    		print(MYFILE "
    ModelCfgIf::GetInstance().CallGetOprndVal($data1,$oprnd_names[$j]);

	
");
			$j++;
    		}
        my $l = 0;
	my $data_value1;
	foreach my $data2(@datas1)
	{
		if ( $data2 eq "IDPID" )
		{
			$data_value1 = "oprnd_value_".$l;
    		print(MYFILE "
    if($data_value1 == 0xFFFFFF)
    {
        return false;
    }

	
");
		}
		elsif ( $data2 eq "FDPID" )
		{
			$data_value1 = "oprnd_value_".$l;
    		print(MYFILE "
    if($data_value1 == 0xFFFFFF)
    {
        return false;
    }

	
");
		}
		elsif ( $data2 eq "SDPID" )
		{
			$data_value1 = "oprnd_value_".$l;
    		print(MYFILE "
    if($data_value1 == 0xFFFFFF)
    {
        return false;
    }

	
");
		}

	$l++;
       }
		my $r = 0;
		my $experssion = $expression_values[$i];
		foreach my $data3(@datas2)
		{
			$experssion =~ s/$data3/$oprnd_names[$r]/g;
			$r++;
		}
    		print(MYFILE "
	if($experssion)
	{
		return true;
	}
	else
	{
		return false;	
	}
");

    		print(MYFILE "
}	
");


	}
close (MYFILE);
}

sub write_subscribe_data(){
	print "write_subscribe_data method....\n";
	$read->setRow(2);
	 for my $row ( $row_min .. $row_max )
    {
    	  my $val_col= $read->getNextRow();
		  if($val_col->[8] ne ""){
			$dpid_fuclassid{$val_col->[8]} = $val_col->[9];
		  }
	}
	my @karr_dpid;
	state $arr_counter=1;
	my @fucls_id = do { my %seen; grep { !$seen{$_}++ } values %dpid_fuclassid}; #unique fuclass_id
	my $size = keys %dpid_fuclassid;
	open (MYFILE, ">>", "$source_file_name");
	print(MYFILE "void InitSubscribeDynamicData(){  ");
	foreach my $fucls(@fucls_id){
		my $size_count = 1;
		my $count=1;
		foreach $k (keys %dpid_fuclassid){
			if(($count le 5) and ($fucls eq $dpid_fuclassid{$k})){
				push(@karr_dpid,$k);
				if($count eq 5){
				$str_arr = join(",",@karr_dpid);
				print(MYFILE "
		eDataPoolId eDPId$arr_counter\[\] = {$str_arr};
		ModelCfgIf::GetInstance().CallDataSubscribe(SUBSCRIBE,5,eDPId$arr_counter,UNUSED); // FU - $dpid_fuclassid{$k}
				");
				$arr_counter++;
				@karr_dpid = ();
				$count = 0;
				}
			}
			# elsif(($count ge 5) and ($fucls eq $dpid_fuclassid{$k})){
				# $count = 0;
			# }
			 elsif(($count lt 5) and ($fucls ne $dpid_fuclassid{$k})){
				$size_count++;
				next;
			 }
			 if(($count lt 5) and ($size_count eq $size)){
				$str_arr = join(",",@karr_dpid);
				print(MYFILE "
		eDataPoolId eDPId$arr_counter\[\] = {$str_arr};
		ModelCfgIf::GetInstance().CallDataSubscribe(SUBSCRIBE,5,eDPId$arr_counter,UNUSED); // FU - $dpid_fuclassid{$k}
				");
				$arr_counter++;
				@karr_dpid = ();
			 }
			$count++;
			$size_count++;
		}
	}
	print "\n",@karr_dpid;
	print(MYFILE "
	}");
	close(MYFILE);
}