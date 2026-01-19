class AuctionSystem{
public:
    map<pair<int,int>,int> bids;
    map<int,set<pair<int,int>>> itemBids;

    AuctionSystem(){}

    void addBid(int userId,int itemId,int bidAmount){
        if(bids.count({userId,itemId})){
            int old=bids[{userId,itemId}];
            itemBids[itemId].erase({old,userId});
        }
        bids[{userId,itemId}]=bidAmount;
        itemBids[itemId].insert({bidAmount,userId});
    }

    void updateBid(int userId,int itemId,int newAmount){
        addBid(userId,itemId,newAmount);
    }

    void removeBid(int userId,int itemId){
        if(!bids.count({userId,itemId})) return;
        int old=bids[{userId,itemId}];
        bids.erase({userId,itemId});
        itemBids[itemId].erase({old,userId});
        if(itemBids[itemId].empty()) itemBids.erase(itemId);
    }

    int getHighestBidder(int itemId){
        if(!itemBids.count(itemId)) return -1;
        return itemBids[itemId].rbegin()->second;
    }
};
