//------------------------------------------------------------------------------
/*
    This file is part of rippled: https://github.com/ripple/rippled
    Copyright (c) 2012, 2013 Ripple Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

//==============================================================================
/*
    2017-06-27  ajochems        Refactored for casinocoin
*/
//==============================================================================

#ifndef CASINOCOIN_PROTOCOL_JSONFIELDS_H_INCLUDED
#define CASINOCOIN_PROTOCOL_JSONFIELDS_H_INCLUDED

#include <casinocoin/json/json_value.h>

namespace casinocoin {
namespace jss {

// JSON static strings

#define JSS(x) constexpr ::Json::StaticString x ( #x )

/* The "StaticString" field names are used instead of string literals to
   optimize the performance of accessing members of Json::Value objects.
*/
// VFALCO What are these nonsense in/out comments?

JSS ( AL_hit_rate );                // out: GetCounts
JSS ( Account );                    // in: TransactionSign; field.
JSS ( Amount );                     // in: TransactionSign; field.
JSS ( ClearFlag );                  // field.
JSS ( Destination );                // in: TransactionSign; field.
JSS ( DeliverMin );                 // in: TransactionSign
JSS ( Fee );                        // in/out: TransactionSign; field.
JSS ( Flags );                      // in/out: TransactionSign; field.
JSS ( Invalid );                    //
JSS ( LastLedgerSequence );         // in: TransactionSign; field
JSS ( LimitAmount );                // field.
JSS ( OfferSequence );              // field.
JSS ( Paths );                      // in/out: TransactionSign
JSS ( TransferRate );               // in: TransferRate
JSS ( historical_perminute );       // historical_perminute
JSS ( SLE_hit_rate );               // out: GetCounts
JSS ( SettleDelay );                // in: TransactionSign
JSS ( SendMax );                    // in: TransactionSign
JSS ( Sequence );                   // in/out: TransactionSign; field.
JSS ( SetFlag );                    // field.
JSS ( SigningPubKey );              // field
JSS ( TakerGets );                  // field.
JSS ( TakerPays );                  // field.
JSS ( TxnSignature );               // field
JSS ( TransactionType );            // in: TransactionSign
JSS ( ClientIP );                   // in/out: TransactionSign; field
JSS ( aborted );                    // out: InboundLedger
JSS ( accepted );                   // out: LedgerToJson, OwnerInfo
JSS ( account );                    // in/out: many
JSS ( accountState );               // out: LedgerToJson
JSS ( accountTreeHash );            // out: ledger/Ledger.cpp
JSS ( account_data );               // out: AccountInfo
JSS ( account_hash );               // out: LedgerToJson
JSS ( account_id );                 // out: WalletPropose
JSS ( account_objects );            // out: AccountObjects
JSS ( account_root );               // in: LedgerEntry
JSS ( accounts );                   // in: LedgerEntry, Subscribe,
                                    //     handlers/Ledger, Unsubscribe
                                    // out: WalletAccounts
JSS ( accounts_proposed );          // in: Subscribe, Unsubscribe
JSS ( action );
JSS ( acquiring );                  // out: LedgerRequest
JSS ( address );                    // out: PeerImp
JSS ( affected );                   // out: AcceptedLedgerTx
JSS ( age );                        // out: NetworkOPs, Peers
JSS ( alternatives );               // out: PathRequest, CasinocoinPathFind
JSS ( amendment_blocked );          // out: NetworkOPs
JSS ( amendments );                 // in: AccountObjects, out: NetworkOPs
JSS ( amount );                     // out: AccountChannels
JSS ( apiEndpoint );                // out: Configuration
JSS ( asks );                       // out: Subscribe
JSS ( assets );                     // out: GatewayBalances
JSS ( authorized );                 // out: AccountLines
JSS ( auth_change );                // out: AccountInfo
JSS ( auth_change_queued );         // out: AccountInfo
JSS ( balance );                    // out: AccountLines
JSS ( balances );                   // out: GatewayBalances
JSS ( base );                       // out: LogLevel
JSS ( base_fee );                   // out: NetworkOPs
JSS ( base_fee_csc );               // out: NetworkOPs
JSS ( bids );                       // out: Subscribe
JSS ( binary );                     // in: AccountTX, LedgerEntry,
                                    //     AccountTxOld, Tx LedgerData
JSS ( books );                      // in: Subscribe, Unsubscribe
JSS ( both );                       // in: Subscribe, Unsubscribe
JSS ( both_sides );                 // in: Subscribe, Unsubscribe
JSS ( build_path );                 // in: TransactionSign
JSS ( build_version );              // out: NetworkOPs
JSS ( cancel_after );               // out: AccountChannels
JSS ( can_delete );                 // out: CanDelete
JSS ( channel_id );                 // out: AccountChannels
JSS ( channels );                   // out: AccountChannels
JSS ( check_nodes );                // in: LedgerCleaner
JSS ( clear );                      // in/out: FetchInfo
JSS ( close_flags );                // out: LedgerToJson
JSS ( close_time );                 // in: Application, out: NetworkOPs,
                                    //      CCLCxPeerPos, LedgerToJson
JSS ( close_time_estimated );       // in: Application, out: LedgerToJson
JSS ( close_time_human );           // out: LedgerToJson
JSS ( close_time_offset );          // out: NetworkOPs
JSS ( close_time_resolution );      // in: Application; out: LedgerToJson
JSS ( closed );                     // out: NetworkOPs, LedgerToJson,
                                    //      handlers/Ledger
JSS ( closed_ledger );              // out: NetworkOPs
JSS ( cluster );                    // out: PeerImp
JSS ( code );                       // out: errors
JSS ( command );                    // in: RPCHandler
JSS ( complete );                   // out: NetworkOPs, InboundLedger
JSS ( complete_ledgers );           // out: NetworkOPs, PeerImp
JSS ( configuration );              // out: RPCHandler
JSS ( consensus );                  // out: NetworkOPs, LedgerConsensus
JSS ( contactEmail );              // in/out: Configuration
JSS ( converge_time );              // out: NetworkOPs
JSS ( converge_time_s );            // out: NetworkOPs
JSS ( count );                      // in: AccountTx*
JSS ( currency );                   // in: paths/PathRequest, STAmount
                                    // out: paths/Node, STPathSet, STAmount
JSS ( current );                    // out: OwnerInfo
JSS ( current_ledger_size );        // out: TxQ
JSS ( current_queue_size );         // out: TxQ
JSS ( data );                       // out: LedgerData
JSS ( date );                       // out: tx/Transaction, NetworkOPs
JSS ( dbKBLedger );                 // out: getCounts
JSS ( dbKBTotal );                  // out: getCounts
JSS ( dbKBTransaction );            // out: getCounts
JSS ( debug_signing );              // in: TransactionSign
JSS ( delivered_amount );           // out: addPaymentDeliveredAmount
JSS ( deprecated );                 // out: WalletSeed
JSS ( descending );                 // in: AccountTx*
JSS ( destination_account );        // in: PathRequest, CasinocoinPathFind, account_lines
                                    // out: AccountChannels
JSS ( destination_amount );         // in: PathRequest, CasinocoinPathFind
JSS ( destination_currencies );     // in: PathRequest, CasinocoinPathFind
JSS ( dest_public_key_hex );        // in: EncryptMsgHandler
JSS ( destination_tag );            // in: PathRequest
                                    // out: AccountChannels
JSS ( dir_entry );                  // out: DirectoryEntryIterator
JSS ( dir_index );                  // out: DirectoryEntryIterator
JSS ( dir_root );                   // out: DirectoryEntryIterator
JSS ( directory );                  // in: LedgerEntry
JSS ( drops );                      // out: TxQ
JSS ( duration_us );                // out: NetworkOPs
JSS ( enabled );                    // out: AmendmentTable
JSS ( encrypted_message );          // out: EncryptMsgHandler
JSS ( engine_result );              // out: NetworkOPs, TransactionSign, Submit
JSS ( engine_result_code );         // out: NetworkOPs, TransactionSign, Submit
JSS ( engine_result_message );      // out: NetworkOPs, TransactionSign, Submit
JSS ( error );                      // out: error
JSS ( error_code );                 // out: error
JSS ( error_exception );            // out: Submit
JSS ( error_message );              // out: error
JSS ( escrow );                     // in: LedgerEntry
JSS ( expand );                     // in: handler/Ledger
JSS ( expected_ledger_size );       // out: TxQ
JSS ( expiration );                 // out: AccountOffers, AccountChannels
JSS ( fail_hard );                  // in: Sign, Submit
JSS ( failed );                     // out: InboundLedger
JSS ( feature );                    // in: Feature
JSS ( features );                   // out: Feature
JSS ( fee );                        // out: NetworkOPs, Peers
JSS ( fee_base );                   // out: NetworkOPs
JSS ( fee_div_max );                // in: TransactionSign
JSS ( fee_level );                  // out: AccountInfo
JSS ( fee_mult_max );               // in: TransactionSign
JSS ( fee_ref );                    // out: NetworkOPs
JSS ( fetch_pack );                 // out: NetworkOPs
JSS ( first );                      // out: rpc/Version
JSS ( fix_txns );                   // in: LedgerCleaner
JSS ( flags );                      // out: paths/Node, AccountOffers,
                                    //      NetworkOPs
JSS ( forward );                    // in: AccountTx
JSS ( freeze );                     // out: AccountLines
JSS ( freeze_peer );                // out: AccountLines
JSS ( frozen_balances );            // out: GatewayBalances
JSS ( full );                       // in: LedgerClearer, handlers/Ledger
JSS ( fullName );                   // out: Configuration
JSS ( full_reply );                 // out: PathFind
JSS ( fullbelow_size );             // in: GetCounts
JSS ( generator );                  // in: LedgerEntry
JSS ( good );                       // out: RPCVersion
JSS ( hash );                       // out: NetworkOPs, InboundLedger,
                                    //      LedgerToJson, STTx; field
JSS ( hashes );                     // in: AccountObjects
JSS ( have_header );                // out: InboundLedger
JSS ( have_state );                 // out: InboundLedger
JSS ( have_transactions );          // out: InboundLedger
JSS ( highest_sequence );           // out: AccountInfo
JSS ( hostid );                     // out: NetworkOPs
JSS ( hotwallet );                  // in: GatewayBalances
JSS ( iconURL );                    // out: Configuration
JSS ( id );                         // websocket.
JSS ( ident );                      // in: AccountCurrencies, AccountInfo,
                                    //     OwnerInfo
JSS ( inLedger );                   // out: tx/Transaction
JSS ( inbound );                    // out: PeerImp
JSS ( index );                      // in: LedgerEntry; out: PathState,
                                    //     STLedgerEntry, LedgerEntry,
                                    //     TxHistory, LedgerData;
                                    // field
JSS ( info );                       // out: ServerInfo, ConsensusInfo, FetchInfo
JSS ( internal_command );           // in: Internal
JSS ( io_latency_ms );              // out: NetworkOPs
JSS ( ip );                         // in: Connect, out: OverlayImpl
JSS ( issuer );                     // in: CasinocoinPathFind, Subscribe,
                                    //     Unsubscribe, BookOffers
                                    // out: paths/Node, STPathSet, STAmount
JSS ( jsonrpc );                    // json version
JSS ( key );                        // out: WalletSeed
JSS ( key_type );                   // in/out: WalletPropose, TransactionSign
JSS ( latency );                    // out: PeerImp
JSS ( last );                       // out: RPCVersion
JSS ( last_close );                 // out: NetworkOPs
JSS ( ledger );                     // in: NetworkOPs, LedgerCleaner,
                                    //     RPCHelpers
                                    // out: NetworkOPs, PeerImp
JSS ( ledger_current_index );       // out: NetworkOPs, RPCHelpers,
                                    //      LedgerCurrent, LedgerAccept
JSS ( ledger_data );                // out: LedgerHeader
JSS ( ledger_hash );                // in: RPCHelpers, LedgerRequest,
                                    //     CasinocoinPathFind, TransactionEntry,
                                    //     handlers/Ledger
                                    // out: NetworkOPs, RPCHelpers,
                                    //      LedgerClosed, LedgerData
JSS ( ledger_hit_rate );            // out: GetCounts
JSS ( ledger_index );               // in/out: many
JSS ( ledger_index_max );           // in, out: AccountTx*
JSS ( ledger_index_min );           // in, out: AccountTx*
JSS ( ledger_max );                 // in, out: AccountTx*
JSS ( ledger_min );                 // in, out: AccountTx*
JSS ( ledger_time );                // out: NetworkOPs
JSS ( levels );                     // LogLevels
JSS ( limit );                      // in/out: AccountTx*, AccountOffers,
                                    //         AccountLines, AccountObjects
                                    // in: LedgerData, BookOffers
JSS ( limit_peer );                 // out: AccountLines
JSS ( lines );                      // out: AccountLines
JSS ( load );                       // out: NetworkOPs, PeerImp
JSS ( load_base );                  // out: NetworkOPs
JSS ( load_factor );                // out: NetworkOPs
JSS ( load_factor_cluster );        // out: NetworkOPs
JSS ( load_factor_fee_escalation ); // out: NetworkOPs
JSS ( load_factor_fee_queue );      // out: NetworkOPs
JSS ( load_factor_fee_reference );  // out: NetworkOPs
JSS ( load_factor_local );          // out: NetworkOPs
JSS ( load_factor_net );            // out: NetworkOPs
JSS ( load_factor_server );         // out: NetworkOPs
JSS ( load_fee );                   // out: LoadFeeTrackImp, NetworkOPs
JSS ( local );                      // out: resource/Logic.h
JSS ( local_txs );                  // out: GetCounts
JSS ( lowest_sequence );            // out: AccountInfo
JSS ( majority );                   // out: RPC feature
JSS ( marker );                     // in/out: AccountTx, AccountOffers,
                                    //         AccountLines, AccountObjects,
                                    //         LedgerData
                                    // in: BookOffers
JSS ( master_key );                 // out: WalletPropose
JSS ( master_seed );                // out: WalletPropose
JSS ( master_seed_hex );            // out: WalletPropose
JSS ( master_signature );           // out: pubManifest
JSS ( max_ledger );                 // in/out: LedgerCleaner
JSS ( max_queue_size );             // out: TxQ
JSS ( max_spend_drops );            // out: AccountInfo
JSS ( max_spend_drops_total );      // out: AccountInfo
JSS ( median_fee );                 // out: TxQ
JSS ( median_level );               // out: TxQ
JSS ( message );                    // error.
JSS ( meta );                       // out: NetworkOPs, AccountTx*, Tx
JSS ( metaData );
JSS ( metadata );                   // out: TransactionEntry
JSS ( method );                     // RPC
JSS ( min_count );                  // in: GetCounts
JSS ( min_ledger );                 // in: LedgerCleaner
JSS ( minimum_fee );                // out: TxQ
JSS ( minimum_level );              // out: TxQ
JSS ( missingCommand );             // error or Message to encrypt
JSS ( name );                       // out: AmendmentTableImpl, PeerImp
JSS ( needed_state_hashes );        // out: InboundLedger
JSS ( needed_transaction_hashes );  // out: InboundLedger
JSS ( network_ledger );             // out: NetworkOPs
JSS ( no_casinocoin );                  // out: AccountLines
JSS ( no_casinocoin_peer );             // out: AccountLines
JSS ( node );                       // out: LedgerEntry
JSS ( node_binary );                // out: LedgerEntry
JSS ( node_hit_rate );              // out: GetCounts
JSS ( node_read_bytes );            // out: GetCounts
JSS ( node_reads_hit );             // out: GetCounts
JSS ( node_reads_total );           // out: GetCounts
JSS ( node_writes );                // out: GetCounts
JSS ( node_written_bytes );         // out: GetCounts
JSS ( nodes );                      // out: PathState
JSS ( obligations );                // out: GatewayBalances
JSS ( offer );                      // in: LedgerEntry
JSS ( offers );                     // out: NetworkOPs, AccountOffers, Subscribe
JSS ( offline );                    // in: TransactionSign
JSS ( offset );                     // in/out: AccountTxOld
JSS ( open );                       // out: handlers/Ledger
JSS ( open_ledger_fee );            // out: TxQ
JSS ( open_ledger_level );          // out: TxQ
JSS ( owner );                      // in: LedgerEntry, out: NetworkOPs
JSS ( owner_funds );                // in/out: Ledger, NetworkOPs, AcceptedLedgerTx
JSS ( params );                     // RPC
JSS ( parent_close_time );          // out: LedgerToJson
JSS ( parent_hash );                // out: LedgerToJson
JSS ( partition );                  // in: LogLevel
JSS ( passphrase );                 // in: WalletPropose
JSS ( password );                   // in: Subscribe
JSS ( paths );                      // in: CasinocoinPathFind
JSS ( paths_canonical );            // out: CasinocoinPathFind
JSS ( paths_computed );             // out: PathRequest, CasinocoinPathFind
JSS ( payment_channel );            // in: LedgerEntry
JSS ( peer );                       // in: AccountLines
JSS ( peer_authorized );            // out: AccountLines
JSS ( peer_id );                    // out: CCLCxPeerPos
JSS ( peers );                      // out: InboundLedger, handlers/Peers, Overlay
JSS ( port );                       // in: Connect
JSS ( previous_ledger );            // out: LedgerPropose
JSS ( proof );                      // in: BookOffers
JSS ( propose_seq );                // out: LedgerPropose
JSS ( proposers );                  // out: NetworkOPs, LedgerConsensus
JSS ( protocol );                   // out: PeerImp
JSS ( pubkey_node );                // out: NetworkOPs
JSS ( pubkey_validator );           // out: NetworkOPs
JSS ( public_key );                 // out: OverlayImpl, PeerImp, WalletPropose
JSS ( public_key_hex );             // out: WalletPropose
JSS ( published_ledger );           // out: NetworkOPs
JSS ( quality );                    // out: NetworkOPs
JSS ( quality_in );                 // out: AccountLines
JSS ( quality_out );                // out: AccountLines
JSS ( queue );                      // in: AccountInfo
JSS ( queue_data );                 // out: AccountInfo
JSS ( random );                     // out: Random
JSS ( raw_meta );                   // out: AcceptedLedgerTx
JSS ( receive_currencies );         // out: AccountCurrencies
JSS ( reference_level );            // out: TxQ
JSS ( regular_seed );               // in/out: LedgerEntry
JSS ( remote );                     // out: Logic.h
JSS ( request );                    // RPC
JSS ( reserve_base );               // out: NetworkOPs
JSS ( reserve_base_csc );           // out: NetworkOPs
JSS ( reserve_inc );                // out: NetworkOPs
JSS ( reserve_inc_csc );            // out: NetworkOPs
JSS ( response );                   // websocket
JSS ( result );                     // RPC
JSS ( casinocoin_lines );               // out: NetworkOPs
JSS ( casinocoin_state );               // in: LedgerEntr
JSS ( casinocoinrpc );                  // casinocoin RPC version
JSS ( role );                       // out: Ping.cpp
JSS ( rt_accounts );                // in: Subscribe, Unsubscribe
JSS ( sanity );                     // out: PeerImp
JSS ( search_depth );               // in: CasinocoinPathFind
JSS ( secret );                     // in: TransactionSign, WalletSeed,
                                    //     ValidationCreate, ValidationSeed,
                                    //     channel_authorize
JSS ( seed );                       // in: WalletAccounts, out: WalletSeed
JSS ( seed_hex );                   // in: WalletPropose, TransactionSign
JSS ( send_currencies );            // out: AccountCurrencies
JSS ( send_max );                   // in: PathRequest, CasinocoinPathFind
JSS ( seq );                        // in: LedgerEntry;
                                    // out: NetworkOPs, RPCSub, AccountOffers
JSS ( seqNum );                     // out: LedgerToJson
JSS ( server_state );               // out: NetworkOPs
JSS ( server_status );              // out: NetworkOPs
JSS ( settle_delay );               // out: AccountChannels
JSS ( severity );                   // in: LogLevel
JSS ( signature );                  // out: NetworkOPs, ChannelAuthorize
JSS ( signature_verified );         // out: ChannelVerify
JSS ( signing_key );                // out: NetworkOPs
JSS ( signing_time );               // out: NetworkOPs
JSS ( signer_list );                // in: AccountObjects
JSS ( signer_lists );               // in/out: AccountInfo
JSS ( snapshot );                   // in: Subscribe
JSS ( source_account );             // in: PathRequest, CasinocoinPathFind
JSS ( source_amount );              // in: PathRequest, CasinocoinPathFind
JSS ( source_currencies );          // in: PathRequest, CasinocoinPathFind
JSS ( source_tag );                 // out: AccountChannels
JSS ( src_public_key_hex );         // in: DecryptMsgHandler
JSS ( stand_alone );                // out: NetworkOPs
JSS ( start );                      // in: TxHistory
JSS ( state );                      // out: Logic.h, ServerState, LedgerData
JSS ( state_accounting );           // out: NetworkOPs
JSS ( state_now );                  // in: Subscribe
JSS ( status );                     // error
JSS ( stop );                       // in: LedgerCleaner
JSS ( streams );                    // in: Subscribe, Unsubscribe
JSS ( strict );                     // in: AccountCurrencies, AccountInfo
JSS ( sub_index );                  // in: LedgerEntry
JSS ( subcommand );                 // in: PathFind
JSS ( success );                    // rpc
JSS ( supported );                  // out: AmendmentTableImpl
JSS ( system_time_offset );         // out: NetworkOPs
JSS ( tag );                        // out: Peers
JSS ( taker );                      // in: Subscribe, BookOffers
JSS ( taker_gets );                 // in: Subscribe, Unsubscribe, BookOffers
JSS ( taker_gets_funded );          // out: NetworkOPs
JSS ( taker_pays );                 // in: Subscribe, Unsubscribe, BookOffers
JSS ( taker_pays_funded );          // out: NetworkOPs
JSS ( threshold );                  // in: Blacklist
JSS ( ticket );                     // in: AccountObjects
JSS ( timeouts );                   // out: InboundLedger
JSS ( traffic );                    // out: Overlay
JSS ( token );                      // out: RPC token
JSS ( totalCoins );                 // out: LedgerToJson
JSS ( total_coins );                // out: LedgerToJson
JSS ( totalSupply );                // out: Configuration
JSS ( transTreeHash );              // out: ledger/Ledger.cpp
JSS ( transaction );                // in: Tx
                                    // out: NetworkOPs, AcceptedLedgerTx,
JSS ( transaction_hash );           // out: CCLCxPeerPos, LedgerToJson
JSS ( transactions );               // out: LedgerToJson,
                                    // in: AccountTx*, Unsubscribe
JSS ( transitions );                // out: NetworkOPs
JSS ( treenode_cache_size );        // out: GetCounts
JSS ( treenode_track_size );        // out: GetCounts
JSS ( trusted );                    // out: UnlList
JSS ( tx );                         // out: STTx, AccountTx*
JSS ( tx_blob );                    // in/out: Submit,
                                    // in: TransactionSign, AccountTx*
JSS ( tx_hash );                    // in: TransactionEntry
JSS ( tx_json );                    // in/out: TransactionSign
                                    // out: TransactionEntry
JSS ( tx_signing_hash );            // out: TransactionSign
JSS ( tx_unsigned );                // out: TransactionSign
JSS ( txn_count );                  // out: NetworkOPs
JSS ( txs );                        // out: TxHistory
JSS ( type );                       // in: AccountObjects
                                    // out: NetworkOPs
                                    //      paths/Node.cpp, OverlayImpl, Logic
JSS ( type_hex );                   // out: STPathSet
JSS ( unl );                        // out: UnlList
JSS ( unlimited);                   // out: Connection.h
JSS ( uptime );                     // out: GetCounts
JSS ( url );                        // in/out: Subscribe, Unsubscribe
JSS ( url_password );               // in: Subscribe
JSS ( url_username );               // in: Subscribe
JSS ( urlgravatar );                //
JSS ( username );                   // in: Subscribe
JSS ( validated );                  // out: NetworkOPs, RPCHelpers, AccountTx*
                                    //      Tx
JSS ( validated_ledger );           // out: NetworkOPs
JSS ( validated_ledgers );          // out: NetworkOPs
JSS ( validation_key );             // out: ValidationCreate, ValidationSeed
JSS ( validation_private_key );     // out: ValidationCreate
JSS ( validation_public_key );      // out: ValidationCreate, ValidationSeed
JSS ( validation_quorum );          // out: NetworkOPs
JSS ( validation_seed );            // out: ValidationCreate, ValidationSeed
JSS ( validations );                // out: AmendmentTableImpl
JSS ( value );                      // out: STAmount
JSS ( version );                    // out: RPCVersion
JSS ( vetoed );                     // out: AmendmentTableImpl
JSS ( vote );                       // in: Feature
JSS ( warning );                    // rpc:
JSS ( website );                    // out: Configuration
JSS ( write_load );                 // out: GetCounts

JSS ( last_refresh_time );          // out: Remote Update Sites
JSS ( last_refresh_status );        // out: Remote Update Sites
JSS ( refresh_interval_min );       // out: Remote Update Sites

#undef JSS

} // jss
} // casinocoin

#endif
