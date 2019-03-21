(* INCOMPLETE 
	 ToDo:
   1. For "Go LEFT" case, edit "Balancing cases":
			balancing factors are not handled correctly.
			Marked with "BF BUG"
	 2. Finish "Go RIHGT" case:
			This will be fairly easy once "Go LEFT" is finished, since
			"Go LEFT" and "Go RIGHT" are symmetric to each others.
	 3. Test.
	 4. Compare with vanila BST.
*)

(* AVL BST data structure. *)
type 'a node = 
          { key        : int;
            value      : 'a;
            bf         : int; (* Balancing factor *)
            left_tree  : 'a bst;
            right_tree : 'a bst }
and 'a bst =
| Empty
| Node of 'a node;;

(* Used to let parent node know which subtree was added.
   If new node, return NONE to indicate all subtrees are empty. *)
type indicator =
| LEFT | RIGHT | NONE
;;

(*** Helper functions for insert & delete ***)
(* Return node record of a tree. Use this ONLY when node is not Empty *)
let return_tree_record node =
  match node with
  | Node n -> n
  | Empty -> failwith "Empty node... cannot return record!";
;;

(* INCOMPLETE function: may be useful for finishing ToDo1.
let calculate_bf left_tree right_tree =
	match left_tree, right_tree with
  | Empty, Empty  -> 0
  | Node l, Empty ->
   if l.bf=0 then
     
   else
     failwith "Should NOT happen, from calculate_bf";
  | Empty, Node r ->
   if r.bf=0 then
     0
   else
     failwith "Should NOT happen, from calculate_bf";
;;
*)

(*** AVL insert ***)
let rec insert bst key elem =
	match bst with
  (* EMPTY: Add a node *)
	| Empty ->
		let newNode = Node({key=key;value=elem;bf=0;left_tree=Empty;right_tree=Empty}) in
		(newNode, NONE)
	(* Go LEFT *)
	| Node parent when parent.key > key ->
	begin
		let left_child, indicator = insert parent.left_tree key elem in
    let left_node = return_tree_record left_child in
    match parent.bf,left_node.bf with
    | 0, 0 | -1, 0 | 1, 0 -> (*Do nothing*)
			let newNode = Node({parent with left_tree=left_child}) in
      (newNode,LEFT)
    | 0, 1 | 0, -1        -> (*Set BF to 1*)
      let newNode = Node({parent with left_tree=left_child; bf=1}) in
      (newNode,LEFT)
    | -1, 1 | -1, -1      -> (*Set BF to 0*)
      let newNode = Node({parent with left_tree=left_child; bf=0}) in
      (newNode,LEFT)
    | 1, 1 | 1, -1        -> (*FUN PART: Balance!*)
    (*Apply LL or LR transform.
      Note that Indicator should NOT be NONE.*)
		begin
			match indicator with
      | LEFT  ->
      	let beta      = left_node.left_tree           in
       	let gamma     = parent.right_tree             in
       	(* Construct balanced tree *)
       	let b = Node({parent with bf=0;left_tree=beta;right_tree=gamma}) in
       	let a = Node({left_node with bf=0;right_tree=b}) in
       	(a,NONE)
      | RIGHT ->
      	let right_node_of_left_node = return_tree_record left_node.right_tree in
 
      	let alpha = left_node.left_tree                in
       	let beta  = right_node_of_left_node.left_tree  in
       	let gamma = right_node_of_left_node.right_tree in
       	let delta = parent.right_tree                  in
       	(* Construct balanced tree *)
       	let a = Node({left_node with bf=0;left_tree=alpha;right_tree=beta}) in
       	let c = Node({parent with bf=0;left_tree=gamma;right_tree=delta}) in
       	let b = Node({right_node_of_left_node with bf=0;left_tree=a;right_tree=c}) in
       	(b,NONE)
      | NONE  ->
       	failwith "indicator Should NOT be NONE at this point...";
		end
		| _ -> (*This should NOT happen*)
   		failwith "This should NOT happen: insert";
	end
	(* Go RIGHT *)
	| Node parent when parent.key < key ->
		(**************)
    (* INCOMPLETE *)
		let newNode = Node({parent with bf=0}) in
		(newNode,NONE)
	(* UPDATE *)
	| Node parent when parent.key = key ->
		let newNode = Node({parent with value=elem}) in 
    (newNode, NONE)
	(* ERROR *)
  | _ ->
   	failwith "ERROR";
