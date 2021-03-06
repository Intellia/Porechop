cmake_minimum_required(VERSION 3.1)
project(porechop CXX C)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES
        include/seqan/align/align_base.h
        include/seqan/align/align_cols.h
        include/seqan/align/align_config.h
        include/seqan/align/align_interface_wrapper.h
        include/seqan/align/align_iterator_base.h
        include/seqan/align/align_metafunctions.h
        include/seqan/align/align_traceback.h
        include/seqan/align/alignment_algorithm_tags.h
        include/seqan/align/alignment_operations.h
        include/seqan/align/dp_algorithm_impl.h
        include/seqan/align/dp_align_simd_helper.h
        include/seqan/align/dp_band.h
        include/seqan/align/dp_cell.h
        include/seqan/align/dp_cell_affine.h
        include/seqan/align/dp_cell_dynamic.h
        include/seqan/align/dp_cell_linear.h
        include/seqan/align/dp_context.h
        include/seqan/align/dp_formula.h
        include/seqan/align/dp_formula_affine.h
        include/seqan/align/dp_formula_dynamic.h
        include/seqan/align/dp_formula_linear.h
        include/seqan/align/dp_matrix.h
        include/seqan/align/dp_matrix_navigator.h
        include/seqan/align/dp_matrix_navigator_score_matrix.h
        include/seqan/align/dp_matrix_navigator_score_matrix_sparse.h
        include/seqan/align/dp_matrix_navigator_trace_matrix.h
        include/seqan/align/dp_matrix_sparse.h
        include/seqan/align/dp_meta_info.h
        include/seqan/align/dp_profile.h
        include/seqan/align/dp_scout.h
        include/seqan/align/dp_scout_simd.h
        include/seqan/align/dp_setup.h
        include/seqan/align/dp_trace_segment.h
        include/seqan/align/dp_traceback_adaptor.h
        include/seqan/align/dp_traceback_impl.h
        include/seqan/align/evaluate_alignment.h
        include/seqan/align/fragment.h
        include/seqan/align/gap_anchor.h
        include/seqan/align/gapped_value_type.h
        include/seqan/align/gaps_anchor.h
        include/seqan/align/gaps_array.h
        include/seqan/align/gaps_base.h
        include/seqan/align/gaps_iterator_anchor.h
        include/seqan/align/gaps_iterator_array.h
        include/seqan/align/gaps_iterator_base.h
        include/seqan/align/global_alignment_banded.h
        include/seqan/align/global_alignment_hirschberg_impl.h
        include/seqan/align/global_alignment_myers_hirschberg_impl.h
        include/seqan/align/global_alignment_myers_impl.h
        include/seqan/align/global_alignment_specialized.h
        include/seqan/align/global_alignment_unbanded.h
        include/seqan/align/local_alignment_banded.h
        include/seqan/align/local_alignment_banded_waterman_eggert_impl.h
        include/seqan/align/local_alignment_enumeration.h
        include/seqan/align/local_alignment_enumeration_banded.h
        include/seqan/align/local_alignment_enumeration_unbanded.h
        include/seqan/align/local_alignment_unbanded.h
        include/seqan/align/local_alignment_waterman_eggert_impl.h
        include/seqan/align/matrix_base.h
        include/seqan/align_extend/align_extend.h
        include/seqan/align_extend/align_extend_base.h
        include/seqan/align_extend/dp_scout_xdrop.h
        include/seqan/align_profile/add_to_profile.h
        include/seqan/align_profile/score_profile_seq.h
        include/seqan/align_split/align_split_interface.h
        include/seqan/align_split/dp_scout_split.h
        include/seqan/alignment_free/af_d2.h
        include/seqan/alignment_free/af_d2star.h
        include/seqan/alignment_free/af_d2z.h
        include/seqan/alignment_free/af_n2.h
        include/seqan/alignment_free/alignment_free_base.h
        include/seqan/alignment_free/alignment_free_comparison.h
        include/seqan/alignment_free/kmer_functions.h
        include/seqan/arg_parse/arg_parse_argument.h
        include/seqan/arg_parse/arg_parse_ctd_support.h
        include/seqan/arg_parse/arg_parse_doc.h
        include/seqan/arg_parse/arg_parse_exceptions.h
        include/seqan/arg_parse/arg_parse_option.h
        include/seqan/arg_parse/arg_parse_parse.h
        include/seqan/arg_parse/arg_parse_type_support.h
        include/seqan/arg_parse/arg_parse_version_check.h
        include/seqan/arg_parse/argument_parser.h
        include/seqan/arg_parse/tool_doc.h
        include/seqan/arg_parse/xml_support.h
        include/seqan/bam_io/bam_alignment_record.h
        include/seqan/bam_io/bam_alignment_record_util.h
        include/seqan/bam_io/bam_file.h
        include/seqan/bam_io/bam_header_record.h
        include/seqan/bam_io/bam_index_bai.h
        include/seqan/bam_io/bam_io_context.h
        include/seqan/bam_io/bam_sam_conversion.h
        include/seqan/bam_io/bam_scanner_cache.h
        include/seqan/bam_io/bam_tags_dict.h
        include/seqan/bam_io/cigar.h
        include/seqan/bam_io/read_bam.h
        include/seqan/bam_io/read_sam.h
        include/seqan/bam_io/write_bam.h
        include/seqan/bam_io/write_sam.h
        include/seqan/basic/aggregate_concept.h
        include/seqan/basic/allocator_chunkpool.h
        include/seqan/basic/allocator_interface.h
        include/seqan/basic/allocator_multipool.h
        include/seqan/basic/allocator_simple.h
        include/seqan/basic/allocator_singlepool.h
        include/seqan/basic/allocator_to_std.h
        include/seqan/basic/alphabet_adapt_builtins.h
        include/seqan/basic/alphabet_bio.h
        include/seqan/basic/alphabet_concept.h
        include/seqan/basic/alphabet_math.h
        include/seqan/basic/alphabet_profile.h
        include/seqan/basic/alphabet_qualities.h
        include/seqan/basic/alphabet_residue.h
        include/seqan/basic/alphabet_residue_funcs.h
        include/seqan/basic/alphabet_residue_tabs.h
        include/seqan/basic/alphabet_simple_type.h
        include/seqan/basic/alphabet_storage.h
        include/seqan/basic/array_construct_destruct.h
        include/seqan/basic/basic_aggregate.h
        include/seqan/basic/basic_allocator.h
        include/seqan/basic/basic_alphabet.h
        include/seqan/basic/basic_concept.h
        include/seqan/basic/basic_container.h
        include/seqan/basic/basic_debug.h
        include/seqan/basic/basic_device.h
        include/seqan/basic/basic_exception.h
        include/seqan/basic/basic_functors.h
        include/seqan/basic/basic_fundamental.h
        include/seqan/basic/basic_iterator.h
        include/seqan/basic/basic_math.h
        include/seqan/basic/basic_metaprogramming.h
        include/seqan/basic/basic_parallelism.h
        include/seqan/basic/basic_proxy.h
        include/seqan/basic/basic_simd_vector.h
        include/seqan/basic/basic_smart_pointer.h
        include/seqan/basic/basic_stream.h
        include/seqan/basic/basic_tangle.h
        include/seqan/basic/basic_type.h
        include/seqan/basic/basic_view.h
        include/seqan/basic/boost_preprocessor_subset.h
        include/seqan/basic/builtin_functions.h
        include/seqan/basic/concept_checking.h
        include/seqan/basic/container_concept.h
        include/seqan/basic/debug_helper.h
        include/seqan/basic/debug_test_system.h
        include/seqan/basic/fundamental_chunking.h
        include/seqan/basic/fundamental_comparison.h
        include/seqan/basic/fundamental_concepts.h
        include/seqan/basic/fundamental_conversion.h
        include/seqan/basic/fundamental_metafunctions.h
        include/seqan/basic/fundamental_tags.h
        include/seqan/basic/fundamental_transport.h
        include/seqan/basic/holder_base.h
        include/seqan/basic/holder_simple.h
        include/seqan/basic/holder_tristate.h
        include/seqan/basic/hosted_type_interface.h
        include/seqan/basic/iterator_adapt_pointer.h
        include/seqan/basic/iterator_adapt_std.h
        include/seqan/basic/iterator_adaptor.h
        include/seqan/basic/iterator_base.h
        include/seqan/basic/iterator_concept.h
        include/seqan/basic/iterator_counting.h
        include/seqan/basic/iterator_interface.h
        include/seqan/basic/iterator_position.h
        include/seqan/basic/iterator_range.h
        include/seqan/basic/iterator_zip.h
        include/seqan/basic/macro_deprecated.h
        include/seqan/basic/math_functions.h
        include/seqan/basic/math_log_space_value.h
        include/seqan/basic/metaprogramming_control.h
        include/seqan/basic/metaprogramming_enable_if.h
        include/seqan/basic/metaprogramming_logic.h
        include/seqan/basic/metaprogramming_math.h
        include/seqan/basic/metaprogramming_type.h
        include/seqan/basic/metaprogramming_type_algebra.h
        include/seqan/basic/pair_base.h
        include/seqan/basic/pair_bit_compressed.h
        include/seqan/basic/pair_packed.h
        include/seqan/basic/profiling.h
        include/seqan/basic/property_map_concept.h
        include/seqan/basic/proxy_base.h
        include/seqan/basic/proxy_iterator.h
        include/seqan/basic/test_system.h
        include/seqan/basic/triple_base.h
        include/seqan/basic/triple_packed.h
        include/seqan/basic/tuple_base.h
        include/seqan/basic/tuple_bit_compressed.h
        include/seqan/basic/volatile_ptr.h
        include/seqan/bed_io/bed_file.h
        include/seqan/bed_io/bed_record.h
        include/seqan/bed_io/read_bed.h
        include/seqan/bed_io/write_bed.h
        include/seqan/blast/blast_base.h
        include/seqan/blast/blast_io_context.h
        include/seqan/blast/blast_record.h
        include/seqan/blast/blast_report_out.h
        include/seqan/blast/blast_statistics.h
        include/seqan/blast/blast_tabular.h
        include/seqan/blast/blast_tabular_in.h
        include/seqan/blast/blast_tabular_lowlevel.h
        include/seqan/blast/blast_tabular_out.h
        include/seqan/consensus/consensus_aligner.h
        include/seqan/consensus/consensus_aligner_interface.h
        include/seqan/consensus/consensus_alignment_options.h
        include/seqan/consensus/consensus_base.h
        include/seqan/consensus/consensus_builder.h
        include/seqan/consensus/consensus_library.h
        include/seqan/consensus/consensus_realign.h
        include/seqan/consensus/consensus_score.h
        include/seqan/consensus/overlap_info_computation.h
        include/seqan/consensus/overlapper.h
        include/seqan/file/file_base.h
        include/seqan/file/file_cstyle.h
        include/seqan/file/file_forwards.h
        include/seqan/file/file_interface.h
        include/seqan/file/file_mapping.h
        include/seqan/file/file_page.h
        include/seqan/file/string_external.h
        include/seqan/file/string_mmap.h
        include/seqan/find/find_abndm.h
        include/seqan/find/find_ahocorasick.h
        include/seqan/find/find_base.h
        include/seqan/find/find_begin.h
        include/seqan/find/find_bndm.h
        include/seqan/find/find_bom.h
        include/seqan/find/find_hamming_simple.h
        include/seqan/find/find_horspool.h
        include/seqan/find/find_lambda.h
        include/seqan/find/find_multi.h
        include/seqan/find/find_multiple_bfam.h
        include/seqan/find/find_multiple_shiftand.h
        include/seqan/find/find_myers_ukkonen.h
        include/seqan/find/find_pattern_base.h
        include/seqan/find/find_pex.h
        include/seqan/find/find_score.h
        include/seqan/find/find_set_horspool.h
        include/seqan/find/find_shiftand.h
        include/seqan/find/find_shiftor.h
        include/seqan/find/find_simple.h
        include/seqan/find/find_wild_shiftand.h
        include/seqan/find/find_wumanber.h
        include/seqan/gff_io/gff_file.h
        include/seqan/gff_io/gff_io_base.h
        include/seqan/graph_algorithms/all_pairs_shortest_path.h
        include/seqan/graph_algorithms/bellman_ford.h
        include/seqan/graph_algorithms/bipartite_matching.h
        include/seqan/graph_algorithms/breadth_first_search.h
        include/seqan/graph_algorithms/connected_components.h
        include/seqan/graph_algorithms/depth_first_search.h
        include/seqan/graph_algorithms/dijkstra.h
        include/seqan/graph_algorithms/floyd_warshall.h
        include/seqan/graph_algorithms/ford_fulkerson.h
        include/seqan/graph_algorithms/graph_algorithm_heap_tree.h
        include/seqan/graph_algorithms/graph_algorithm_hmm.h
        include/seqan/graph_algorithms/graph_algorithm_lis_his.h
        include/seqan/graph_algorithms/kruskal.h
        include/seqan/graph_algorithms/path_growing.h
        include/seqan/graph_algorithms/prim.h
        include/seqan/graph_algorithms/single_source_shortest_path.h
        include/seqan/graph_algorithms/strongly_connected_compnents.h
        include/seqan/graph_algorithms/topological_sort.h
        include/seqan/graph_algorithms/transitive_closure.h
        include/seqan/graph_algorithms/weakly_connected_components.h
        include/seqan/graph_algorithms/weighted_bipartite_matching.h
        include/seqan/graph_align/graph_algorithm_refine_align.h
        include/seqan/graph_align/graph_algorithm_refine_aligngraph.h
        include/seqan/graph_align/graph_algorithm_refine_annotation.h
        include/seqan/graph_align/graph_algorithm_refine_exact.h
        include/seqan/graph_align/graph_algorithm_refine_exact_iterative.h
        include/seqan/graph_align/graph_algorithm_refine_fragment.h
        include/seqan/graph_align/graph_algorithm_refine_inexact.h
        include/seqan/graph_align/graph_algorithm_refine_scoring.h
        include/seqan/graph_align/graph_impl_align.h
        include/seqan/graph_align/graph_impl_align_adapt.h
        include/seqan/graph_msa/graph_align_tcoffee_base.h
        include/seqan/graph_msa/graph_align_tcoffee_distance.h
        include/seqan/graph_msa/graph_align_tcoffee_guidetree.h
        include/seqan/graph_msa/graph_align_tcoffee_io.h
        include/seqan/graph_msa/graph_align_tcoffee_kmer.h
        include/seqan/graph_msa/graph_align_tcoffee_library.h
        include/seqan/graph_msa/graph_align_tcoffee_msa.h
        include/seqan/graph_msa/graph_align_tcoffee_progressive.h
        include/seqan/graph_msa/graph_align_tcoffee_refinement.h
        include/seqan/graph_types/graph_base.h
        include/seqan/graph_types/graph_drawing.h
        include/seqan/graph_types/graph_edgestump.h
        include/seqan/graph_types/graph_idmanager.h
        include/seqan/graph_types/graph_impl_automaton.h
        include/seqan/graph_types/graph_impl_directed.h
        include/seqan/graph_types/graph_impl_hmm.h
        include/seqan/graph_types/graph_impl_oracle.h
        include/seqan/graph_types/graph_impl_tree.h
        include/seqan/graph_types/graph_impl_trie.h
        include/seqan/graph_types/graph_impl_undirected.h
        include/seqan/graph_types/graph_impl_wordgraph.h
        include/seqan/graph_types/graph_interface.h
        include/seqan/graph_types/graph_iterator.h
        include/seqan/graph_types/graph_iterator_adjacency.h
        include/seqan/graph_types/graph_iterator_bfs.h
        include/seqan/graph_types/graph_iterator_dfs.h
        include/seqan/graph_types/graph_iterator_edge.h
        include/seqan/graph_types/graph_iterator_outedge.h
        include/seqan/graph_types/graph_iterator_vertex.h
        include/seqan/graph_types/graph_utility_parsing.h
        include/seqan/graph_types/property_map_generic.h
        include/seqan/graph_types/property_map_internal.h
        include/seqan/graph_types/property_map_internal_pointer.h
        include/seqan/index/find2_backtracking.h
        include/seqan/index/find2_base.h
        include/seqan/index/find2_functors.h
        include/seqan/index/find2_index.h
        include/seqan/index/find2_index_multi.h
        include/seqan/index/find2_vstree_factory.h
        include/seqan/index/find_backtracking.h
        include/seqan/index/find_index.h
        include/seqan/index/find_index_approx.h
        include/seqan/index/find_index_binary.h
        include/seqan/index/find_index_esa.h
        include/seqan/index/find_index_lambda.h
        include/seqan/index/find_index_qgram.h
        include/seqan/index/find_pigeonhole.h
        include/seqan/index/find_quasar.h
        include/seqan/index/find_swift.h
        include/seqan/index/index_base.h
        include/seqan/index/index_bidirectional.h
        include/seqan/index/index_bidirectional_stree.h
        include/seqan/index/index_bifm.h
        include/seqan/index/index_bifm_stree.h
        include/seqan/index/index_bwt.h
        include/seqan/index/index_childtab.h
        include/seqan/index/index_device.h
        include/seqan/index/index_dfi.h
        include/seqan/index/index_esa_algs.h
        include/seqan/index/index_esa_algs_multi.h
        include/seqan/index/index_esa_base.h
        include/seqan/index/index_esa_drawing.h
        include/seqan/index/index_esa_stree.h
        include/seqan/index/index_fm.h
        include/seqan/index/index_fm_compressed_sa.h
        include/seqan/index/index_fm_compressed_sa_iterator.h
        include/seqan/index/index_fm_dox.h
        include/seqan/index/index_fm_lf_table.h
        include/seqan/index/index_fm_rank_dictionary_base.h
        include/seqan/index/index_fm_rank_dictionary_levels.h
        include/seqan/index/index_fm_rank_dictionary_naive.h
        include/seqan/index/index_fm_rank_dictionary_wt.h
        include/seqan/index/index_fm_right_array_binary_tree.h
        include/seqan/index/index_fm_right_array_binary_tree_iterator.h
        include/seqan/index/index_fm_sparse_string.h
        include/seqan/index/index_fm_stree.h
        include/seqan/index/index_forwards.h
        include/seqan/index/index_lcp.h
        include/seqan/index/index_lcp_tree.h
        include/seqan/index/index_pizzachili.h
        include/seqan/index/index_pizzachili_find.h
        include/seqan/index/index_pizzachili_string.h
        include/seqan/index/index_qgram.h
        include/seqan/index/index_qgram_bucketrefinement.h
        include/seqan/index/index_qgram_openaddressing.h
        include/seqan/index/index_qgram_stree.h
        include/seqan/index/index_sa_btree.h
        include/seqan/index/index_sa_bwtwalk.h
        include/seqan/index/index_sa_lss.h
        include/seqan/index/index_sa_mm.h
        include/seqan/index/index_sa_qsort.h
        include/seqan/index/index_sa_stree.h
        include/seqan/index/index_sa_truncated.h
        include/seqan/index/index_shawarma.h
        include/seqan/index/index_shims.h
        include/seqan/index/index_skew3.h
        include/seqan/index/index_skew7.h
        include/seqan/index/index_skew7_multi.h
        include/seqan/index/index_view.h
        include/seqan/index/index_wotd.h
        include/seqan/index/pipe_merger3.h
        include/seqan/index/pipe_merger7.h
        include/seqan/index/pizzachili_api.h
        include/seqan/index/pump_extender3.h
        include/seqan/index/pump_extender7.h
        include/seqan/index/pump_lcp_core.h
        include/seqan/index/pump_separator7.h
        include/seqan/index/radix.h
        include/seqan/index/repeat_base.h
        include/seqan/index/shape_base.h
        include/seqan/index/shape_gapped.h
        include/seqan/index/shape_minimizer.h
        include/seqan/index/shape_onegapped.h
        include/seqan/index/shape_predefined.h
        include/seqan/index/shape_threshold.h
        include/seqan/journaled_set/journal_alignment_interface.h
        include/seqan/journaled_set/journal_alignment_traceback_adaptor.h
        include/seqan/journaled_set/journaled_set_base.h
        include/seqan/journaled_set/journaled_set_impl.h
        include/seqan/journaled_set/journaled_set_join.h
        include/seqan/journaled_set/journaled_set_join_config.h
        include/seqan/journaled_set/journaled_set_join_global_align_compact.h
        include/seqan/journaled_set/journaled_set_join_global_align_manhatten.h
        include/seqan/journaled_set/journaled_set_journal_trace_descriptor.h
        include/seqan/journaled_set/score_biaffine.h
        include/seqan/journaled_string_tree/delta_map.h
        include/seqan/journaled_string_tree/delta_map_entry.h
        include/seqan/journaled_string_tree/delta_map_iterator.h
        include/seqan/journaled_string_tree/delta_store.h
        include/seqan/journaled_string_tree/journaled_string_tree_base.h
        include/seqan/journaled_string_tree/journaled_string_tree_impl.h
        include/seqan/journaled_string_tree/journaled_string_tree_sequence_buffer.h
        include/seqan/journaled_string_tree/journaled_string_tree_traverser.h
        include/seqan/journaled_string_tree/journaled_string_tree_traverser_node.h
        include/seqan/journaled_string_tree/journaled_string_tree_traverser_util.h
        include/seqan/journaled_string_tree/jst_extension_base.h
        include/seqan/journaled_string_tree/jst_extension_horspool.h
        include/seqan/journaled_string_tree/jst_extension_myers_ukkonen.h
        include/seqan/journaled_string_tree/jst_extension_shiftand.h
        include/seqan/journaled_string_tree/jst_extension_shiftor.h
        include/seqan/journaled_string_tree/observable.h
        include/seqan/journaled_string_tree/stack_observer.h
        include/seqan/map/map_adapter_stl.h
        include/seqan/map/map_base.h
        include/seqan/map/map_chooser.h
        include/seqan/map/map_skiplist.h
        include/seqan/map/map_vector.h
        include/seqan/map/sumlist.h
        include/seqan/map/sumlist_mini.h
        include/seqan/map/sumlist_skip.h
        include/seqan/math/math_common_factor.h
        include/seqan/math/math_operators.h
        include/seqan/math/math_rational.h
        include/seqan/misc/accumulators.h
        include/seqan/misc/base.h
        include/seqan/misc/bit_twiddling.h
        include/seqan/misc/bit_twiddling_functors.h
        include/seqan/misc/dequeue.h
        include/seqan/misc/edit_environment.h
        include/seqan/misc/interval_tree.h
        include/seqan/misc/map.h
        include/seqan/misc/memset.h
        include/seqan/misc/name_store_cache.h
        include/seqan/misc/priority_type_base.h
        include/seqan/misc/priority_type_heap.h
        include/seqan/misc/set.h
        include/seqan/misc/svg.h
        include/seqan/misc/terminal.h
        include/seqan/misc/union_find.h
        include/seqan/modifier/cyclic_shape.h
        include/seqan/modifier/modifier_alphabet.h
        include/seqan/modifier/modifier_alphabet_expansion.h
        include/seqan/modifier/modifier_cyclic_shape.h
        include/seqan/modifier/modifier_functors.h
        include/seqan/modifier/modifier_iterator.h
        include/seqan/modifier/modifier_padding.h
        include/seqan/modifier/modifier_position.h
        include/seqan/modifier/modifier_reverse.h
        include/seqan/modifier/modifier_shortcuts.h
        include/seqan/modifier/modifier_string.h
        include/seqan/modifier/modifier_view.h
        include/seqan/parallel/parallel_algorithms.h
        include/seqan/parallel/parallel_atomic_misc.h
        include/seqan/parallel/parallel_atomic_primitives.h
        include/seqan/parallel/parallel_lock.h
        include/seqan/parallel/parallel_macros.h
        include/seqan/parallel/parallel_queue.h
        include/seqan/parallel/parallel_queue_suspendable.h
        include/seqan/parallel/parallel_resource_pool.h
        include/seqan/parallel/parallel_sequence.h
        include/seqan/parallel/parallel_serializer.h
        include/seqan/parallel/parallel_splitting.h
        include/seqan/parallel/parallel_tags.h
        include/seqan/parse_lm/local_match_store.h
        include/seqan/parse_lm/parse_blastn_tabular.h
        include/seqan/parse_lm/parse_lastz_general.h
        include/seqan/parse_lm/parse_stellar_gff.h
        include/seqan/pipe/pipe_base.h
        include/seqan/pipe/pipe_caster.h
        include/seqan/pipe/pipe_counter.h
        include/seqan/pipe/pipe_echoer.h
        include/seqan/pipe/pipe_edit_environment.h
        include/seqan/pipe/pipe_filter.h
        include/seqan/pipe/pipe_iterator.h
        include/seqan/pipe/pipe_joiner.h
        include/seqan/pipe/pipe_namer.h
        include/seqan/pipe/pipe_sampler.h
        include/seqan/pipe/pipe_shifter.h
        include/seqan/pipe/pipe_source.h
        include/seqan/pipe/pipe_tupler.h
        include/seqan/pipe/pool_base.h
        include/seqan/pipe/pool_mapper.h
        include/seqan/pipe/pool_sorter.h
        include/seqan/random/random_base.h
        include/seqan/random/random_beta.h
        include/seqan/random/random_util.h
        include/seqan/realign/realign_base.h
        include/seqan/realign/realign_helper_functions.h
        include/seqan/reduced_aminoacid/reduced_aminoacid_base.h
        include/seqan/reduced_aminoacid/reduced_aminoacid_base_late.h
        include/seqan/reduced_aminoacid/reduced_aminoacid_cluster_red_base.h
        include/seqan/reduced_aminoacid/reduced_aminoacid_cluster_red_tables_20_to_n_b62.h
        include/seqan/reduced_aminoacid/reduced_aminoacid_cluster_red_tables_22_to_n_b62.h
        include/seqan/reduced_aminoacid/reduced_aminoacid_cluster_red_tables_24_to_n_b62.h
        include/seqan/reduced_aminoacid/reduced_aminoacid_murphy10_base.h
        include/seqan/reduced_aminoacid/reduced_aminoacid_murphy10_tables.h
        include/seqan/rna_io/bpseq_read_write.h
        include/seqan/rna_io/connect_read_write.h
        include/seqan/rna_io/dot_bracket_read_write.h
        include/seqan/rna_io/ebpseq_read_write.h
        include/seqan/rna_io/rna_header.h
        include/seqan/rna_io/rna_io_context.h
        include/seqan/rna_io/rna_record.h
        include/seqan/rna_io/rna_struct_file.h
        include/seqan/rna_io/stockholm_read_write.h
        include/seqan/rna_io/vienna_read_write.h
        include/seqan/roi_io/read_roi.h
        include/seqan/roi_io/roi_file.h
        include/seqan/roi_io/roi_io_context.h
        include/seqan/roi_io/roi_record.h
        include/seqan/roi_io/write_roi.h
        include/seqan/score/score_base.h
        include/seqan/score/score_edit.h
        include/seqan/score/score_matrix.h
        include/seqan/score/score_matrix_data.h
        include/seqan/score/score_matrix_dyn.h
        include/seqan/score/score_matrix_io.h
        include/seqan/score/score_simd_wrapper.h
        include/seqan/score/score_simple.h
        include/seqan/seeds/banded_chain_alignment.h
        include/seqan/seeds/banded_chain_alignment_impl.h
        include/seqan/seeds/banded_chain_alignment_profile.h
        include/seqan/seeds/banded_chain_alignment_scout.h
        include/seqan/seeds/banded_chain_alignment_traceback.h
        include/seqan/seeds/basic_iter_indirect.h
        include/seqan/seeds/seeds_base.h
        include/seqan/seeds/seeds_combination.h
        include/seqan/seeds/seeds_extension.h
        include/seqan/seeds/seeds_global_chaining.h
        include/seqan/seeds/seeds_global_chaining_base.h
        include/seqan/seeds/seeds_global_chaining_gusfield.h
        include/seqan/seeds/seeds_seed_base.h
        include/seqan/seeds/seeds_seed_chained.h
        include/seqan/seeds/seeds_seed_diagonal.h
        include/seqan/seeds/seeds_seed_set_base.h
        include/seqan/seeds/seeds_seed_set_non_scored.h
        include/seqan/seeds/seeds_seed_set_scored.h
        include/seqan/seeds/seeds_seed_set_unordered.h
        include/seqan/seeds/seeds_seed_simple.h
        include/seqan/seq_io/bam_sam.h
        include/seqan/seq_io/fai_index.h
        include/seqan/seq_io/fasta_fastq.h
        include/seqan/seq_io/genomic_region.h
        include/seqan/seq_io/read_embl.h
        include/seqan/seq_io/read_genbank.h
        include/seqan/seq_io/sequence_file.h
        include/seqan/sequence/adapt_array_pointer.h
        include/seqan/sequence/adapt_stl_container.h
        include/seqan/sequence/container_view.h
        include/seqan/sequence/container_view_zip.h
        include/seqan/sequence/iter_concat_virtual.h
        include/seqan/sequence/segment_base.h
        include/seqan/sequence/segment_infix.h
        include/seqan/sequence/segment_prefix.h
        include/seqan/sequence/segment_suffix.h
        include/seqan/sequence/segment_utils.h
        include/seqan/sequence/sequence_concatenator.h
        include/seqan/sequence/sequence_forwards.h
        include/seqan/sequence/sequence_interface.h
        include/seqan/sequence/sequence_lexical.h
        include/seqan/sequence/sequence_shortcuts.h
        include/seqan/sequence/string_alloc.h
        include/seqan/sequence/string_array.h
        include/seqan/sequence/string_base.h
        include/seqan/sequence/string_block.h
        include/seqan/sequence/string_cstyle.h
        include/seqan/sequence/string_packed.h
        include/seqan/sequence/string_packed_old.h
        include/seqan/sequence/string_set_base.h
        include/seqan/sequence/string_set_concat_direct.h
        include/seqan/sequence/string_set_dependent_generous.h
        include/seqan/sequence/string_set_dependent_tight.h
        include/seqan/sequence/string_set_owner.h
        include/seqan/sequence/string_set_segment.h
        include/seqan/sequence/string_set_view.h
        include/seqan/sequence_journaled/journal_entries_sorted_array.h
        include/seqan/sequence_journaled/journal_entry.h
        include/seqan/sequence_journaled/sequence_journaled.h
        include/seqan/sequence_journaled/sequence_journaled_iterator.h
        include/seqan/sequence_journaled/sequence_journaled_iterator_fast.h
        include/seqan/simple_intervals_io/simple_intervals_file.h
        include/seqan/simple_intervals_io/simple_intervals_io.h
        include/seqan/statistics/statistics_base.h
        include/seqan/statistics/statistics_markov_model.h
        include/seqan/store/store_align.h
        include/seqan/store/store_align_intervals.h
        include/seqan/store/store_all.h
        include/seqan/store/store_annotation.h
        include/seqan/store/store_base.h
        include/seqan/store/store_contig.h
        include/seqan/store/store_intervaltree.h
        include/seqan/store/store_io.h
        include/seqan/store/store_io_gff.h
        include/seqan/store/store_io_sam.h
        include/seqan/store/store_io_ucsc.h
        include/seqan/store/store_library.h
        include/seqan/store/store_matepair.h
        include/seqan/store/store_read.h
        include/seqan/stream/adapt_ios.h
        include/seqan/stream/buffered_stream.h
        include/seqan/stream/file_stream.h
        include/seqan/stream/formatted_file.h
        include/seqan/stream/guess_format.h
        include/seqan/stream/iostream_bgzf.h
        include/seqan/stream/iostream_bzip2.h
        include/seqan/stream/iostream_bzip2_impl.h
        include/seqan/stream/iostream_zip.h
        include/seqan/stream/iostream_zip_impl.h
        include/seqan/stream/iostream_zutil.h
        include/seqan/stream/iter_stream.h
        include/seqan/stream/lexical_cast.h
        include/seqan/stream/stream_base.h
        include/seqan/stream/stream_compressor.h
        include/seqan/stream/tokenization.h
        include/seqan/stream/virtual_stream.h
        include/seqan/system/file_async.h
        include/seqan/system/file_directory.h
        include/seqan/system/file_forwards.h
        include/seqan/system/file_sync.h
        include/seqan/system/system_base.h
        include/seqan/system/system_event_win.h
        include/seqan/system/system_forwards.h
        include/seqan/tabix_io/tabix_index_tbi.h
        include/seqan/translation/translation.h
        include/seqan/translation/translation_tables.h
        include/seqan/ucsc_io/ucsc_file.h
        include/seqan/ucsc_io/ucsc_io.h
        include/seqan/ucsc_io/ucsc_record.h
        include/seqan/vcf_io/read_vcf.h
        include/seqan/vcf_io/vcf_file.h
        include/seqan/vcf_io/vcf_header.h
        include/seqan/vcf_io/vcf_header_record.h
        include/seqan/vcf_io/vcf_io_context.h
        include/seqan/vcf_io/vcf_record.h
        include/seqan/vcf_io/write_vcf.h
        include/seqan/align.h
        include/seqan/align_extend.h
        include/seqan/align_profile.h
        include/seqan/align_split.h
        include/seqan/alignment_free.h
        include/seqan/arg_parse.h
        include/seqan/bam_io.h
        include/seqan/basic.h
        include/seqan/bed_io.h
        include/seqan/blast.h
        include/seqan/consensus.h
        include/seqan/file.h
        include/seqan/find.h
        include/seqan/gff_io.h
        include/seqan/graph_algorithms.h
        include/seqan/graph_align.h
        include/seqan/graph_msa.h
        include/seqan/graph_types.h
        include/seqan/index.h
        include/seqan/journaled_set.h
        include/seqan/journaled_string_tree.h
        include/seqan/map.h
        include/seqan/math.h
        include/seqan/modifier.h
        include/seqan/parallel.h
        include/seqan/parse_lm.h
        include/seqan/pipe.h
        include/seqan/platform.h
        include/seqan/random.h
        include/seqan/realign.h
        include/seqan/reduced_aminoacid.h
        include/seqan/rna_io.h
        include/seqan/roi_io.h
        include/seqan/score.h
        include/seqan/seeds.h
        include/seqan/seq_io.h
        include/seqan/sequence.h
        include/seqan/sequence_journaled.h
        include/seqan/simple_intervals_io.h
        include/seqan/statistics.h
        include/seqan/store.h
        include/seqan/stream.h
        include/seqan/system.h
        include/seqan/tabix_io.h
        include/seqan/translation.h
        include/seqan/ucsc_io.h
        include/seqan/vcf_io.h
        include/seqan/version.h
        include/adapter_align.h
        include/alignment.h
        src/adapter_align.cpp
        src/alignment.cpp
        )

include_directories(include)

add_library(cpp_functions SHARED ${SOURCE_FILES})

set_target_properties(cpp_functions
        PROPERTIES OUTPUT_NAME cpp_functions)

install(TARGETS cpp_functions
        LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}
        )

if (APPLE)
    SET(cpp_functions_lib "libcpp_functions.dylib")
ELSEIF (LINUX)
    SET(cpp_functions_lib "libcpp_functions.so")
ENDIF ()

IF(CMAKE_BUILD_TYPE MATCHES Debug)
    add_executable(dummy main.cpp ${SOURCE_FILES})
ENDIF(CMAKE_BUILD_TYPE MATCHES DEBUG)