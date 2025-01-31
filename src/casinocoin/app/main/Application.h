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
    2017-06-26  ajochems        Refactored for casinocoin
*/
//==============================================================================

#ifndef CASINOCOIN_APP_MAIN_APPLICATION_H_INCLUDED
#define CASINOCOIN_APP_MAIN_APPLICATION_H_INCLUDED

#include <casinocoin/shamap/FullBelowCache.h>
#include <casinocoin/shamap/TreeNodeCache.h>
#include <casinocoin/basics/TaggedCache.h>
#include <casinocoin/core/Config.h>
#include <casinocoin/beast/utility/PropertyStream.h>
#include <memory>
#include <mutex>

namespace boost { namespace asio { class io_service; } }

namespace casinocoin {

namespace unl { class Manager; }
namespace Resource { class Manager; }
namespace NodeStore { class Database; }

// VFALCO TODO Fix forward declares required for header dependency loops
class VotableConfiguration;
class AmendmentTable;
class CachedSLEs;
class CollectorManager;
class Family;
class HashRouter;
class Logs;
class LoadFeeTrack;
class JobQueue;
class InboundLedgers;
class InboundTransactions;
class AcceptedLedger;
class LedgerMaster;
class LoadManager;
class ManifestCache;
class NetworkOPs;
class OpenLedger;
class OrderBookDB;
class Overlay;
class PathRequests;
class PendingSaves;
class PublicKey;
class SecretKey;
class AccountIDCache;
class STLedgerEntry;
class TimeKeeper;
class TransactionMaster;
class TxQ;
class Validations;
class ValidatorList;
class ValidatorSite;
class Cluster;

class DatabaseCon;
class SHAMapStore;

class Blacklist;
class BlacklistUpdater;

using NodeCache     = TaggedCache <SHAMapHash, Blob>;

class Application : public beast::PropertyStream::Source
{
public:
    /* VFALCO NOTE

        The master mutex protects:

        - The open ledger
        - Server global state
            * What the last closed ledger is
            * State of the consensus engine

        other things
    */
    using MutexType = std::recursive_mutex;
    virtual MutexType& getMasterMutex () = 0;

public:
    Application ();

    virtual ~Application () = default;

    virtual bool setup() = 0;
    virtual void doStart(bool withTimers) = 0;
    virtual void run() = 0;
    virtual bool isShutdown () = 0;
    virtual void signalStop () = 0;
    virtual bool checkSigs() const = 0;
    virtual void checkSigs(bool) = 0;

    //
    // ---
    //

    virtual Logs& logs() = 0;
    virtual Config& config() = 0;
    virtual boost::asio::io_service& getIOService () = 0;
    virtual CollectorManager&       getCollectorManager () = 0;
    virtual Family&                 family() = 0;
    virtual TimeKeeper&             timeKeeper() = 0;
    virtual JobQueue&               getJobQueue () = 0;
    virtual NodeCache&              getTempNodeCache () = 0;
    virtual CachedSLEs&             cachedSLEs() = 0;
    virtual AmendmentTable&         getAmendmentTable() = 0;
    virtual VotableConfiguration&   getVotableConfig() = 0;
    virtual HashRouter&             getHashRouter () = 0;
    virtual LoadFeeTrack&           getFeeTrack () = 0;
    virtual LoadManager&            getLoadManager () = 0;
    virtual Overlay&                overlay () = 0;
    virtual TxQ&                    getTxQ() = 0;
    virtual ValidatorList&          validators () = 0;
    virtual ValidatorSite&          validatorSites () = 0;
    virtual ManifestCache&          validatorManifests () = 0;
    virtual ManifestCache&          publisherManifests () = 0;
    virtual Cluster&                cluster () = 0;
    virtual Validations&            getValidations () = 0;
    virtual NodeStore::Database&    getNodeStore () = 0;
    virtual InboundLedgers&         getInboundLedgers () = 0;
    virtual InboundTransactions&    getInboundTransactions () = 0;
    virtual TaggedCache <uint256, AcceptedLedger>&
                                    getAcceptedLedgerCache () = 0;
    virtual LedgerMaster&           getLedgerMaster () = 0;
    virtual NetworkOPs&             getOPs () = 0;
    virtual OrderBookDB&            getOrderBookDB () = 0;
    virtual TransactionMaster&      getMasterTransaction () = 0;

    virtual
    std::pair<PublicKey, SecretKey> const&
    nodeIdentity () = 0;

    virtual Resource::Manager&      getResourceManager () = 0;
    virtual PathRequests&           getPathRequests () = 0;
    virtual SHAMapStore&            getSHAMapStore () = 0;
    virtual PendingSaves&           pendingSaves() = 0;
    virtual AccountIDCache const&   accountIDCache() const = 0;
    virtual OpenLedger&             openLedger() = 0;
    virtual OpenLedger const&       openLedger() const = 0;
    virtual DatabaseCon& getTxnDB () = 0;
    virtual DatabaseCon& getLedgerDB () = 0;

    virtual Blacklist&              blacklistedAccounts () = 0;
    virtual BlacklistUpdater&       blacklistUpdater () = 0;

    virtual std::chrono::milliseconds getIOLatency () = 0;

    virtual bool serverOkay (std::string& reason) = 0;

    virtual beast::Journal journal (std::string const& name) = 0;

    /* Returns the number of file descriptors the application wants */
    virtual int fdlimit () const = 0;

    /** Retrieve the "wallet database" */
    virtual DatabaseCon& getWalletDB () = 0;
};

std::unique_ptr <Application>
make_Application(
    std::unique_ptr<Config> config,
    std::unique_ptr<Logs> logs,
    std::unique_ptr<TimeKeeper> timeKeeper);

}

#endif
